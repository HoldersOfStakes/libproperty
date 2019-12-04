#ifndef __LIBPROPERTY_BINARY_H__
#define __LIBPROPERTY_BINARY_H__


// System
#include <memory>
#include <string.h>

// Private
#include <property/raw_data.h>


namespace property
{
  class Binary : public RawData
  {
  public:
    Binary();
    Binary(const Binary& other);
    Binary(char* data, ssize_t length);
    Binary(const char* data, ssize_t length);
    ~Binary();

    bool equals(std::shared_ptr<RawData> other_data) override;

    void set(char* data, ssize_t length);
    void set(const char* data, ssize_t length);
    void append(char* data, ssize_t length);
    void append(const char* data, ssize_t length);
    void clear();

    ssize_t size() const;

    const char* getData() const;

  private:
    char* data_;
    ssize_t length_;
  };
} // namespace property


#endif /* __LIBPROPERTY_BINARY_H__*/
