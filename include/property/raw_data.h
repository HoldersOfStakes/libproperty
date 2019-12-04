#ifndef __LIBPROPERTY_RAW_DATA_H__
#define __LIBPROPERTY_RAW_DATA_H__


// System
#include <memory>


namespace property
{
  class RawData
  {
  public:
    RawData() = default;
    virtual ~RawData() = default;

    //virtual bool equals(std::shared_ptr<RawData> other_data) = 0;
  };
} // namespace property


#endif /* __LIBPROPERTY_RAW_DATA_H__ */
