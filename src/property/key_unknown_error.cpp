#include <property/key_unknown_error.h>


namespace property
{
  KeyUnknownError::KeyUnknownError(std::string key)
    : std::runtime_error{ ("Invalid key '" + key + "'") }
  {
  }
} // namespace property
