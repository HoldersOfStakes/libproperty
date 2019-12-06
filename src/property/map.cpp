#include <property/map.h>


namespace property
{
  std::shared_ptr<RawData> Map::copy()
  {
    std::shared_ptr<Map> map_copy = std::make_shared<Map>();

    for(std::pair<std::string, std::shared_ptr<RawData>> pair : *this)
    {
      map_copy->set(pair.first, pair.second);
    }

    return map_copy;
  }

  bool Map::equals(std::shared_ptr<RawData> other_data)
  {
    if(other_data != nullptr)
    {
      std::shared_ptr<Map> map = other_data->as<Map>();

      if(map->size() == this->size())
      {
        for(std::pair<std::string, std::shared_ptr<RawData>> pair : *map)
        {
          if(!this->isMember(pair.first))
          {
            return false;
          }
        }

        for(std::pair<std::string, std::shared_ptr<RawData>> pair : *this)
        {
          if(!map->isMember(pair.first))
          {
            return false;
          }
        }

        return true;
      }
    }

    return false;
  }

  void Map::set(std::string key, std::shared_ptr<RawData> data)
  {
    children_[key] = data;
  }

  bool Map::isMember(std::string key)
  {
    return children_.find(key) != children_.end();
  }

  void Map::clear()
  {
    children_.clear();
  }

  void Map::remove(std::string key)
  {
    children_.erase(key);
  }

  void Map::erase(Map::iterator it)
  {
    children_.erase(it);
  }

  ssize_t Map::size() const
  {
    return children_.size();
  }

  Map::iterator Map::begin()
  {
    return children_.begin();
  }

  Map::iterator Map::end()
  {
    return children_.end();
  }

  std::shared_ptr<RawData> Map::at(std::string key)
  {
    if(children_.find(key) == children_.end())
    {
      throw KeyUnknownError(key);
    }

    return children_[key];
  }
} // namespace property
