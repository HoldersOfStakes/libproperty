#ifndef __LIBPROPERTY_DATA_H__
#define __LIBPROPERTY_DATA_H__


// System
#include <memory>

// Private
#include <property/raw_data.h>


namespace property
{
  class Data
  {
  public:
    Data();
    virtual ~Data();

  private:
    std::shared_ptr<RawData> raw_data_;
  };
} // namespace property


#endif /* __LIBPROPERTY_DATA_H__ */
