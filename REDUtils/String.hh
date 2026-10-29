#ifndef RED_String_hh
#define RED_String_hh

#include <string>
#include <iostream>

namespace RED {

  namespace String {

    // The following functions support Percent-encoding for URI and HTTP.
    std::string PercentEncode(std::string::const_iterator begin, std::string::const_iterator end);
    std::string PercentEncode(const std::string &in, std::string::size_type pos = 0);
    std::string PercentEncode(const std::string &in, std::string::size_type pos, std::string::size_type len = std::string::npos);
    std::string PercentDecode(std::string::const_iterator begin, std::string::const_iterator end);
    std::string PercentDecode(const std::string &in, std::string::size_type pos = 0);
    std::string PercentDecode(const std::string &in, std::string::size_type pos, std::string::size_type len = std::string::npos);

    struct URI_parts {
      std::string scheme;
      std::string authority;
      std::string path;
      std::string query;
      std::string fragment;
    };
    // Split URI provided into pieces. Decode if necessary.
    URI_parts SplitURI(const std::string& uri);

  } // namespace String

} // namespace RED

std::ostream& operator<<(std::ostream& os, const RED::String::URI_parts &URI);


#endif /* RED_String_hh */
