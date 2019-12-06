#include <property/binary.h>


namespace property
{
  Binary::Binary()
    : data_{ nullptr }
    , length_{ 0 }
  {
  }

  Binary::Binary(const Binary& other)
    : RawData()
  {
    data_ = new char[other.length_];
    memcpy(data_, other.data_, other.length_);
    length_ = other.length_;
  }

  Binary::Binary(char* data, ssize_t length)
    : data_{ nullptr }
    , length_{ 0 }
  {
    set(data, length);
  }

  Binary::Binary(const char* data, ssize_t length)
    : data_{ nullptr }
    , length_{ 0 }
  {
    set(data, length);
  }

  Binary::~Binary()
  {
    clear();
  }

  bool Binary::equals(std::shared_ptr<RawData> other_data)
  {
    if(other_data != nullptr)
    {
      std::shared_ptr<Binary> binary = other_data->as<Binary>();

      if(binary->size() == this->size())
      {
      }
    }

    return false;
  }

  void Binary::set(const char* data, ssize_t length)
  {
    clear();

    data_ = new char[length];
    length_ = length;

    memcpy(data_, data, length);
  }

  void Binary::set(char* data, ssize_t length)
  {
    set(static_cast<const char*>(data), length);
  }

  void Binary::append(const char* data, ssize_t length)
  {
    if(data_ == nullptr)
    {
      set(data, length);
    }
    else
    {
      char* data_temp = new char[length_ + length];
      memcpy(data_temp, data_, length_);
      memcpy(&data_temp[length_], data, length);

      delete[] data_;

      length_ += length;
      data_ = data_temp;
    }
  }

  void Binary::append(char* data, ssize_t length)
  {
    append(static_cast<const char*>(data), length);
  }

  void Binary::clear()
  {
    if(data_ != nullptr)
    {
      delete[] data_;
      data_ = nullptr;
      length_ = 0;
    }
  }

  ssize_t Binary::size() const
  {
    return length_;
  }

  const char* Binary::getData() const
  {
    return data_;
  }
} // namespace property
