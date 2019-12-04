#ifndef __LIBPROPERTY_DATA_LIST_H__
#define __LIBPROPERTY_DATA_LIST_H__


// System
#include <iterator>
#include <list>
#include <memory>

// Private
#include <property/raw_data.h>
#include <property/index_out_of_bounds_error.h>


namespace property
{
  class List : public RawData
  {
  public:
    typedef std::list<std::shared_ptr<RawData>>::iterator iterator;

    List() = default;
    ~List() = default;

    bool equals(std::shared_ptr<RawData> other_data) override;

    void add(std::shared_ptr<RawData> data);
    void clear();

    void remove(std::shared_ptr<RawData> data);
    void erase(iterator it);

    ssize_t size() const;

    iterator begin();
    iterator end();

    std::shared_ptr<RawData> at(unsigned int index);

  private:
    std::list<std::shared_ptr<RawData>> children_;
  };
} // namespace property


#endif /* __LIBPROPERTY_DATA_LIST_H__*/
