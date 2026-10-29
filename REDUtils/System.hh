#ifndef RED_System_hh
#define RED_System_hh

#include <string>
#include <vector>

namespace RED {

  namespace System {

    // The following functions do shell-like expansions for variables
    //  and wildcards.
    std::string ExpandPathName(const std::string &in);
    std::vector<std::string> GlobPathName(const std::string &in);
    //std::vector<std::string> ShellExpand(const std::string &in);

  } // namespace System

} // namespace RED

#endif /* RED_System_hh */
