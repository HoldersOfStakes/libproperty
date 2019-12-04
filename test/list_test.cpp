// System
#include <memory>

// Catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

// libscrape
#include <property/raw_data.h>
#include <property/list.h>


TEST_CASE("Data gets added to list", "[list]")
{
  SECTION("When one entry gets added to the list, exactly that entry is in the list.")
  {
    // Arrange.
    std::shared_ptr<property::List> data_list = std::make_shared<property::List>();
    std::shared_ptr<property::RawData> data_content_1 = std::make_shared<property::RawData>();

    // Act.
    data_list->add(data_content_1);

    // Assert.
    REQUIRE(data_list->size() == 1);
    REQUIRE(*(data_list->begin()) == data_content_1);
  }

  SECTION("When two entries get added to the list, exactly those entries are in the list in the correct order.")
  {
    // Arrange.
    std::shared_ptr<property::List> data_list = std::make_shared<property::List>();
    std::shared_ptr<property::RawData> data_content_1 = std::make_shared<property::RawData>();
    std::shared_ptr<property::RawData> data_content_2 = std::make_shared<property::RawData>();

    // Act.
    data_list->add(data_content_1);
    data_list->add(data_content_2);

    // Assert.
    REQUIRE(data_list->size() == 2);

    auto it = data_list->begin();
    
    REQUIRE(*it == data_content_1);
    it++;
    REQUIRE(*it == data_content_2);
  }
}

TEST_CASE("List gets cleared", "[list]")
{
  SECTION("When an entry gets added to the list and the list gets cleared, the list is empty.")
  {
    // Arrange.
    std::shared_ptr<property::List> data_list = std::make_shared<property::List>();
    std::shared_ptr<property::RawData> data_content_1 = std::make_shared<property::RawData>();

    data_list->add(data_content_1);

    // Act.
    data_list->clear();

    // Assert.
    REQUIRE(data_list->size() == 0);
  }
}

TEST_CASE("Accessing elements by index", "[list]")
{
  SECTION("When no entry is contained in a list and an element is accessed by index, an exception is thrown.")
  {
    // Arrange.
    std::shared_ptr<property::List> data_list = std::make_shared<property::List>();

    // Act, Assert.
    CHECK_THROWS_AS(data_list->at(2), property::IndexOutOfBoundsError);
  }
}
