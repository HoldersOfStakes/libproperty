#ifndef __LIBPROPERTY_MAP_H__
#define __LIBPROPERTY_MAP_H__


// System
#include <iterator>
#include <map>
#include <memory>
#include <sstream>

// Private
#include <property/raw_data.h>
#include <property/value.hpp>
#include <property/key_unknown_error.h>


namespace property
{
  class Map : public RawData
  {
  public:
    typedef std::map<std::string, std::shared_ptr<RawData>>::iterator iterator;

    Map() = default;

    std::shared_ptr<RawData> copy() override;
    bool equals(std::shared_ptr<RawData> other_data) override;

    void set(std::string key, std::shared_ptr<RawData> data);
    bool isMember(std::string key);
    void clear();

    void remove(std::string key);
    void erase(iterator it);

    ssize_t size() const;

    iterator begin();
    iterator end();

    std::shared_ptr<RawData> at(std::string key);

    template<typename TValueType>
    bool equalsValueAt(std::string key, TValueType value)
    {
      if(isMember(key))
      {
        std::shared_ptr<Value<TValueType>> value_object = std::dynamic_pointer_cast<Value<TValueType>>(at(key));

        if(value_object != nullptr)
        {
          return value_object->getValue() == value;
        }
      }

      return false;
    }

    template<typename TValueType>
    TValueType getValueOrDefaultAt(std::string key, TValueType default_value)
    {
      if(isMember(key))
      {
        std::shared_ptr<Value<TValueType>> value_object = std::dynamic_pointer_cast<Value<TValueType>>(at(key));

        if(value_object != nullptr)
        {
          return value_object->getValue();
        }
      }

      return default_value;
    }

    template<typename TValueType>
    TValueType getValueAt(std::string key)
    {
      return getValueOrDefaultAt(key, TValueType());
    }

    std::string toString() override;

  private:
    std::map<std::string, std::shared_ptr<RawData>> children_;
  };
} // namespace property


#endif /* __LIBPROPERTY_MAP_H__*/
