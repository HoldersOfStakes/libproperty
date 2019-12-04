// System
#include <memory>

// Catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// libscrape
#include <property/value.hpp>
#include <property/map.h>


TEST_CASE("Data gets added to map", "[map]")
{
  SECTION("When one entry gets added to the map, exactly that entry is in the map.")
  {
    // Arrange.
    const std::string TEST_KEY = "some-key";
    const int TEST_VALUE = 5;
    std::shared_ptr<property::Map> data_map = std::make_shared<property::Map>();
    std::shared_ptr<property::Value<int>> data_content_1 = std::make_shared<property::Value<int>>(TEST_VALUE);

    // Act.
    data_map->set(TEST_KEY, data_content_1);

    // Assert.
    REQUIRE(data_map->size() == 1);
    REQUIRE(data_map->at(TEST_KEY)->as<property::Value<int>>()->getValue() == TEST_VALUE);
  }
}
