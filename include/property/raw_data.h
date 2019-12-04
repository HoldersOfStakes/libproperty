#ifndef __LIBPROPERTY_RAW_DATA_H__
#define __LIBPROPERTY_RAW_DATA_H__


// System
#include <memory>


namespace property
{
  class RawData : public std::enable_shared_from_this<RawData>
  {
  public:
    RawData() = default;
    virtual ~RawData() = default;

    virtual bool equals(std::shared_ptr<RawData> other_data) = 0;

    template<class TType>
    bool is()
    {
      return as<TType>() != nullptr;
    }

    template<class TType>
    std::shared_ptr<TType> as()
    {
      return std::dynamic_pointer_cast<TType>(this->shared_from_this());
    }
  };
} // namespace property


#endif /* __LIBPROPERTY_RAW_DATA_H__ */
