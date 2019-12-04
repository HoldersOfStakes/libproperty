// System
#include <memory>

// Catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// libscrape
#include <property/value.hpp>


TEST_CASE("Value gets stored and retrieved", "[value]")
{
  SECTION("When a value is stored, it can be obtained again.")
  {
    // Arrange.
    const std::string TEST_STRING = "A sample test string.";
    std::shared_ptr<property::Value<std::string>> data = std::make_shared<property::Value<std::string>>(TEST_STRING);

    // Act, Assert.
    REQUIRE(data->getValue() == TEST_STRING);
  }
}
