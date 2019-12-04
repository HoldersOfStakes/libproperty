// System
#include <memory>

// Catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// libscrape
#include <property/binary.h>


TEST_CASE("Binary values get stored and retrieved", "[binary]")
{
  SECTION("When a binary value is stored, it can be obtained again.")
  {
    // Arrange.
    const std::string TEST_STRING = "A sample test string.";
    std::shared_ptr<property::Binary> data = std::make_shared<property::Binary>(TEST_STRING.c_str(), TEST_STRING.size());

    // Act.
    std::string retrieved_data = std::string(data->getData(), data->size());

    // Assert.
    REQUIRE(retrieved_data == TEST_STRING);
  }

  SECTION("When a binary value is stored and the instance is copied, then the value can be obtained from the copy again.")
  {
    // Arrange.
    const std::string TEST_STRING = "A sample test string.";
    property::Binary data_1(property::Binary(TEST_STRING.c_str(), TEST_STRING.size()));
    property::Binary data_2 = data_1;

    // Act.
    std::string retrieved_data = std::string(data_2.getData(), data_2.size());

    // Assert.
    REQUIRE(retrieved_data == TEST_STRING);
  }

  SECTION("When two binary values are appended, then their combination can be retrieved.")
  {
    // Arrange.
    const std::string TEST_STRING_1 = "Hello ";
    const std::string TEST_STRING_2 = "World!";
    property::Binary data(property::Binary(TEST_STRING_1.c_str(), TEST_STRING_1.size()));

    // Act.
    data.append(TEST_STRING_2.c_str(), TEST_STRING_2.size());
    std::string retrieved_data = std::string(data.getData(), data.size());

    // Assert.
    REQUIRE(retrieved_data == TEST_STRING_1 + TEST_STRING_2);
  }
}
