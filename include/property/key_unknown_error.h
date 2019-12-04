#ifndef __LIBPROPERTY_KEY_UNKNOWN_ERROR_H__
#define __LIBPROPERTY_KEY_UNKNOWN_ERROR_H__


// System
#include <stdexcept>
#include <string>


namespace property
{
  class KeyUnknownError : public std::runtime_error
  {
  public:
    KeyUnknownError(std::string key);
    ~KeyUnknownError() = default;
  };
} // namespace property


#endif /* __LIBSCRAPE_KEY_UNKNOWN_ERROR_H__ */
