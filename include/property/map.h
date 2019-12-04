#ifndef __LIBPROPERTY_MAP_H__
#define __LIBPROPERTY_MAP_H__


// System
#include <iterator>
#include <map>
#include <memory>

// Private
#include <property/raw_data.h>
#include <property/key_unknown_error.h>


namespace property
{
  class Map : public RawData
  {
  public:
    typedef std::map<std::string, std::shared_ptr<RawData>>::iterator iterator;

    Map() = default;
    ~Map() = default;

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

  private:
    std::map<std::string, std::shared_ptr<RawData>> children_;
  };
} // namespace property


#endif /* __LIBPROPERTY_MAP_H__*/
