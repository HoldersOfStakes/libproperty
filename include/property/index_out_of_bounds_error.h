#ifndef __LIBPROPERTY_INDEX_OUT_OF_BOUNDS_ERROR_H__
#define __LIBPROPERTY_INDEX_OUT_OF_BOUNDS_ERROR_H__


// System
#include <stdexcept>
#include <string>


namespace property
{
  class IndexOutOfBoundsError : public std::runtime_error
  {
  public:
    IndexOutOfBoundsError(int index, unsigned int item_count);
    ~IndexOutOfBoundsError() = default;
  };
} // namespace property


#endif /* __LIBSCRAPE_DATA_INDEX_OUT_OF_BOUNDS_EXCEPTION_H__ */
