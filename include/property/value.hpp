#ifndef __LIBPROPERTY_VALUE_HPP__
#define __LIBPROPERTY_VALUE_HPP__


// System
#include <sstream>

// Private
#include <property/raw_data.h>


namespace property
{
  template<typename TType>
  class Value : public RawData
  {
  public:
    Value()
      : typed_value_{ TType() }
    {
    }

    Value(TType typed_value)
    : typed_value_{ typed_value }
    {
    }

    ~Value() = default;

    std::shared_ptr<RawData> copy() override
    {
      return std::make_shared<Value<TType>>(typed_value_);
    }

    bool equals(std::shared_ptr<RawData> other_data) override
    {
      if(other_data != nullptr)
      {
        std::shared_ptr<Value<TType>> value = other_data->as<Value<TType>>();

        return value->getValue() == typed_value_;
      }

      return false;
    }

    TType getValue()
    {
      return typed_value_;
    }

    bool operator==(std::shared_ptr<RawData> other_data)
    {
      std::shared_ptr<Value<TType>> other_typed_value = std::dynamic_pointer_cast<Value<TType>>(other_data);

      if(other_typed_value != nullptr)
      {
        return other_typed_value->getValue() == typed_value_;
      }

      return false;
    }

    std::string toString() override
    {
      std::stringstream sts;
      sts << typed_value_;

      return sts.str();
    }

  private:
    TType typed_value_;
  };
} // namespace property


#endif /* __LIBPROPERTY_VALUE_HPP__ */
