#include <property/data.h>


namespace property
{
  Data::Data()
    : raw_data_{ std::make_shared<RawData>() }
  {
  }
} // namespace property
