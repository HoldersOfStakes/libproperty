#include <property/list.h>


namespace property
{
  void List::add(std::shared_ptr<RawData> data)
  {
    children_.emplace_back(data);
  }

  void List::clear()
  {
    children_.clear();
  }

  void List::remove(std::shared_ptr<RawData> data)
  {
    children_.remove(data);
  }

  void List::erase(List::iterator it)
  {
    children_.erase(it);
  }

  ssize_t List::size() const
  {
    return children_.size();
  }

  List::iterator List::begin()
  {
    return children_.begin();
  }

  List::iterator List::end()
  {
    return children_.end();
  }

  std::shared_ptr<RawData> List::at(unsigned int index)
  {
    if(index >= size())
    {
      throw IndexOutOfBoundsError(index, size());
    }

    auto it = begin();
    std::advance(it, index);

    return *it;
  }
} // namespace property
