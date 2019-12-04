#include <property/index_out_of_bounds_error.h>


namespace property
{
  IndexOutOfBoundsError::IndexOutOfBoundsError(int index, unsigned int item_count)
    : std::runtime_error{ ("Invalid index '" + std::to_string(index) + "' (item count '" + std::to_string(item_count) + "')") }
  {
  }
} // namespace property
