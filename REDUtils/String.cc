#include <string>
#include <iostream>

#include "String.hh"

using namespace RED;
using std::string;
using std::ostream;

std::string RED::String::PercentEncode(std::string::const_iterator begin, std::string::const_iterator end)
{
  string out;
  // to be honest we must ensure that string::char_type is char
  for (string::const_iterator it = begin; it != end; it++) {
    if (isalpha(*it) || isdigit(*it) || 
        *it=='-' || *it=='_' || *it=='.' || *it=='~') {
      // pass it
      out.push_back(*it);
    } else {
      // here we assume sizeof(char)==1 char==8bits
      const char digits[] = "0123456789ABCDEF";
      char c = *it;
      out.push_back('%'), out.push_back(digits[(c>>4)&0xf]), out.push_back(digits[c&0xf]);
    }
  }
  return out;
}
std::string RED::String::PercentEncode(const std::string &in, std::string::size_type pos)
{
  std::string::size_type end = in.size();
  if (pos>end) pos = end;
  return PercentEncode(in.begin()+pos, in.end());
}
std::string RED::String::PercentEncode(const std::string &in, std::string::size_type pos, std::string::size_type len)
{
  std::string::size_type end = in.size();
  if (pos>end) pos = end;
  if (len!=std::string::npos && len<end)
    if (pos+len<end) end = pos+len;
  return PercentEncode(in.begin()+pos,in.begin()+end);
}
std::string RED::String::PercentDecode(std::string::const_iterator begin, std::string::const_iterator end)
{
  string out;
  // to be honest we must ensure that string::char_type is char
  for (string::const_iterator it = begin; it != end; it++) {
    if (*it!='%') {
      // pass it
      out.push_back(*it);
    } else {
      // here we assume sizeof(char)==1 char==8bits
      // we also assume that '0-9', 'a-b' and 'A-B' are continuous
      char c = 0; int i, j;
      if (++it==end) break;
      i = 0; c = *it;
      if      ('0'<=c && c<='9') i = c - '0';
      else if ('A'<=c && c<='F') i = c - 'A' + 10;
      else if ('a'<=c && c<='f') i = c - 'a' + 10;
      else { out.push_back(c); continue; }
      if (++it==end) break;
      i <<= 4; c = *it;
      if      ('0'<=c && c<='9') i += c - '0';
      else if ('A'<=c && c<='F') i += c - 'A' + 10;
      else if ('a'<=c && c<='f') i += c - 'a' + 10;
      else { out.push_back(c); continue; }
      out.push_back(char(i)); 
    }
  }
  return out;
}
std::string RED::String::PercentDecode(const std::string &in, std::string::size_type pos)
{
  std::string::size_type end = in.size();
  if (pos>end) pos = end;
  return PercentDecode(in.begin()+pos, in.end());
}
std::string RED::String::PercentDecode(const std::string &in, std::string::size_type pos, std::string::size_type len)
{
  std::string::size_type end = in.size();
  if (pos>end) pos = end;
  if (len!=std::string::npos && len<end)
    if (pos+len<end) end = pos+len;
  return PercentDecode(in.begin()+pos,in.begin()+end);
}

RED::String::URI_parts RED::String::SplitURI(const std::string& uri)
{
  // Generic form: scheme:[//[user:password@]host[:port]][/]path[?query][#fragment]
  URI_parts URI;
  string::size_type i,j,k,l;

  // from the head
  i = uri.find(':');
  if (i!=string::npos)
    URI.scheme.assign(uri,0,i++);
  else
    i = 0;

  // and from tail
  l = uri.rfind('#');
  if (l!=string::npos)
    URI.fragment = PercentDecode(uri,l+1,string::npos);
  k = uri.rfind('?',l);
  if (k!=string::npos)
    URI.query = PercentDecode(uri,k+1,l-k-1);
  else
    k = l;

  // now we have authority+path in [i,k)
  if (i<k) {
    if (i+2<k && uri[i]=='/' && uri[i+1]=='/') {
      // it begins with '//' so it's authority
      i += 2; // skip '//'
      // also path must begin with '/'
      // the next isn't absolutely correct since username could contain '/'
      j = uri.find('/',i);
      if (j<k) // found '/'
        URI.authority.assign(uri,i,j-i), URI.path = PercentDecode(uri,j,k-j);
      else
        URI.authority.assign(i,k-i);
    } else
      URI.path = PercentDecode(uri,i,k-i);
  }

  return URI;
}

ostream& operator<<(ostream& os, const RED::String::URI_parts &URI)
{
  os << "{ "
     << ".scheme = '"    << URI.scheme    << "', "
     << ".authority = '" << URI.authority << "', "
     << ".path = '"      << URI.path      << "', "
     << ".query = '"     << URI.query     << "', "
     << ".fragment = '"  << URI.fragment  << "' "
     << "}";
  return os;
}
