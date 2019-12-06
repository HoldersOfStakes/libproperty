#include <property/list.h>


namespace property
{
  std::shared_ptr<RawData> List::copy()
  {
    std::shared_ptr<List> list_copy = std::make_shared<List>();

    for(std::shared_ptr<RawData> raw_data_child : children_)
    {
      list_copy->add(raw_data_child->copy());
    }

    return list_copy;
  }

  bool List::equals(std::shared_ptr<RawData> other_data)
  {
    if(other_data != nullptr)
    {
      std::shared_ptr<List> list = other_data->as<List>();

      if(list->size() == this->size())
      {
        for(unsigned int i = 0; i < this->size(); ++i)
        {
          if(!this->at(i)->equals(list->at(i)))
          {
            return false;
          }
        }

        return true;
      }
    }

    return false;
  }

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
