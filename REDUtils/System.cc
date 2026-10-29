#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "System.hh"

using namespace RED;
using std::string;
using std::vector;


#include <unistd.h>
#include <pwd.h>
string RED::System::ExpandPathName(const string &in)
{
  string out;

  enum {
    kNormal = 0,
    kTilda,
    kVariable,
    kBracket1, // {}
  } mode;
  mode = kNormal;
  string name;
  for (string::const_iterator it = in.begin(); it != in.end(); it++) {
    switch(mode) {
    case kNormal:
      if      (*it=='~') mode = kTilda;
      else if (*it=='$') mode = kVariable;
      else out.push_back(*it);
      break;
    case kTilda:
      if (isalpha(*it) || *it=='_') name.push_back(*it);
      else {
        struct passwd *pw = (name.empty())?getpwuid(getuid()):getpwnam(name.c_str());
        if (pw!=0 && pw->pw_dir!=0)
          out += pw->pw_dir;
        name.clear();
        mode = kNormal; it--; // restart this letter
      }
      break;
    case kVariable:
      if (*it=='$') {
        long pid = getpid();
        char buf[32];
        snprintf(buf,sizeof(buf),"%ld",pid);
        out += buf;
        mode = kNormal;
      } else if (name.empty() && *it=='{')
        mode = kBracket1;
      else if (isalpha(*it) || *it=='_')
        name.push_back(*it);
      else {
        char *res = getenv(name.c_str());
        if (res!=0) out += res;
        name.clear();
        mode = kNormal; it--; // restart this letter
      }
      break;
    case kBracket1:
      if (*it=='}') {
        size_t i;
        for (i=0;i<name.size();i++)
          if (!(isalpha(name[i]) || name[i]=='_'))
            break;
        name.erase(i,string::npos);
        char *res = getenv(name.c_str());
        if (res!=0) out += res;
        mode = kNormal;
      } else {
        name.push_back(*it);
      }
    }
  }
  switch (mode) {
  case kNormal:
    break;
  case kTilda: {
        struct passwd *pw = (name.empty())?getpwuid(getuid()):getpwnam(name.c_str());
        if (pw!=0 && pw->pw_dir!=0)
          out += pw->pw_dir;
  } break;
  case kVariable:
  case kBracket1: {
        size_t i;
        for (i=0;i<name.size();i++)
          if (!(isalpha(name[i]) || name[i]=='_'))
            break;
        name.erase(i,string::npos);
        char *res = getenv(name.c_str());
        if (res!=0) out += res;
  } break;
  }

  return out;
}
#include <glob.h>
vector<string> RED::System::GlobPathName(const string &in)
{
  vector<string> list;

  if (in.find_first_of("*?[{")==string::npos) {
    // no wildcards found
    list.push_back(in);
    return list;
  }

  glob_t gl;
  // both options are GNU extensions
  int ret = glob(in.c_str(), GLOB_BRACE|GLOB_TILDE, 0, &gl);
  if (ret==0) {
    for (size_t i = 0; i < gl.gl_pathc; i++)
      list.push_back(gl.gl_pathv[i]);
  } else {
    ; // error, we should throw an exception here
  }
  globfree(&gl);
  return list;
}

#include <wordexp.h>
//vector<string> RED::System::ShellExpand(const string &in);
