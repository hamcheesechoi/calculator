#include "gmock/gmock.h"
#include "gilded_rose.h"

using std::vector;
using std::string;

namespace {
    const char* SULFURAS = "Sulfuras, Hand of Ragnaros";
    const char* NONAME = "noname";
    const char* AGED_BRIE = "Aged Brie";
    const char* BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
}

class GR_Fixture : public testing::Test {
protected:
    GildedRose* gr;
    void runTest(Item& item, int expect_sellIn, int expect_quality) {
        vector<Item> items;
        items.emplace_back(item);
        gr = new GildedRose(items);
        gr->updateQuality();

        EXPECT_EQ(expect_sellIn, items[0].sellIn);
        EXPECT_EQ(expect_quality, items[0].quality);
    }

    void SetUp() override {
    }
    void TearDown() override {
        delete gr;
    }
};

TEST(GildedRoseTest, Foo) {
    //Arrange
    vector<Item> items;
    //items.push_back(Item(NONAME, 0, 0));
    items.emplace_back(NONAME, 0, 0);
    GildedRose app(items);

    //Act
    app.updateQuality();

    //Arrange
    EXPECT_EQ(NONAME, app.items[0].name);
}

TEST(GildedRoseTest, TC1) {
    //Arrange
    vector<Item> items;
    items.emplace_back(NONAME, 10, 30);
    GildedRose app(items);
    int expect_quality = 29;
    int expect_sellin = 9;

    //Act
    app.updateQuality();

    //Arrange
    for (Item item : app.items) {
        EXPECT_EQ(expect_quality, item.quality);
        EXPECT_EQ(expect_sellin, item.sellIn);
    }
    
}
TEST(GildedRoseTest, TC2) {
    //Arrange
    vector<Item> items;
    items.emplace_back(BACKSTAGE_PASS, 15, 30);
    GildedRose app(items);
    int expect_quality = 31;
    int expect_sellin = 14;

    //Act
    app.updateQuality();

    //Arrange
    for (Item item : app.items) {
        EXPECT_EQ(expect_quality, item.quality);
        EXPECT_EQ(expect_sellin, item.sellIn);
    }
}
TEST(GildedRoseTest, TC3) {
    //Arrange
    vector<Item> items;
    items.emplace_back(BACKSTAGE_PASS, 10, 30);
    GildedRose app(items);
    int expect_quality = 32;
    int expect_sellin = 9;

    //Act
    app.updateQuality();

    //Arrange
    for (Item item : app.items) {
        EXPECT_EQ(expect_quality, item.quality);
        EXPECT_EQ(expect_sellin, item.sellIn);
    }
}
TEST(GildedRoseTest, TC4) {
    //Arrange
    vector<Item> items;
    items.emplace_back(BACKSTAGE_PASS, 5, 30);
    GildedRose app(items);
    int expect_quality = 33;
    int expect_sellin = 4;

    //Act
    app.updateQuality();

    //Arrange
    for (Item item : app.items) {
        EXPECT_EQ(expect_quality, item.quality);
        EXPECT_EQ(expect_sellin, item.sellIn);
    }
}
TEST(GildedRoseTest, TC5) {
    //Arrange
    vector<Item> items;
    items.emplace_back(NONAME, 0, 30);
    GildedRose app(items);
    int expect_quality = 28;
    int expect_sellin = -1;

    //Act
    app.updateQuality();

    //Arrange
    for (Item item : app.items) {
        EXPECT_EQ(expect_quality, item.quality);
        EXPECT_EQ(expect_sellin, item.sellIn);
    }
}
TEST(GildedRoseTest, TC6) {
    //Arrange
    vector<Item> items;
    items.emplace_back(BACKSTAGE_PASS, 0, 30);
    GildedRose app(items);
    int expect_quality = 0;
    int expect_sellin = -1;

    //Act
    app.updateQuality();

    //Arrange
    for (Item item : app.items) {
        EXPECT_EQ(expect_quality, item.quality);
        EXPECT_EQ(expect_sellin, item.sellIn);
    }
}
TEST(GildedRoseTest, TC7) {
    //Arrange
    vector<Item> items;
    items.emplace_back(AGED_BRIE, 0, 30);
    GildedRose app(items);
    int expect_quality = 32;
    int expect_sellin = -1;

    //Act
    app.updateQuality();

    //Arrange
    for (Item item : app.items) {
        EXPECT_EQ(expect_quality, item.quality);
        EXPECT_EQ(expect_sellin, item.sellIn);
    }
}
TEST(GildedRoseTest, ShuleBeNothingWhenNoItem) {
    vector<Item> items;
    GildedRose app{ items };
    
    app.updateQuality();

    EXPECT_EQ(0, items.size());
}

TEST(GildedRoseTest, NoNameSellin0Quality0) {
    vector<Item> items;
    items.emplace_back(NONAME, 0, 0);
    GildedRose app{ items };

    app.updateQuality();

    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(0, items[0].quality);
}

TEST(GildedRoseTest, NoNameSellin0Quality1) {
    vector<Item> items;
    items.emplace_back(NONAME, 0, 1);
    GildedRose app{ items };

    app.updateQuality();

    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(0, items[0].quality);
}

TEST(GildedRoseTest, SulfurasSellin0Quality80) {
    vector<Item> items;
    items.emplace_back(SULFURAS, 0, 80);
    GildedRose app{ items };

    app.updateQuality();

    EXPECT_EQ(0, items[0].sellIn);
    EXPECT_EQ(80, items[0].quality);
}

TEST(GildedRoseTest, SulfurasSellinM2Quality80) {
    vector<Item> items;
    items.emplace_back(SULFURAS, -2, 80);
    GildedRose app{ items };

    app.updateQuality();

    EXPECT_EQ(-2, items[0].sellIn);
    EXPECT_EQ(80, items[0].quality);
}

TEST(GildedRoseTest_Foo_Test, AgedBrieSellin0Quality0) {
    vector<Item> items;
    items.emplace_back(AGED_BRIE, 0, 0);
    GildedRose app{ items };

    app.updateQuality();

    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(2, items[0].quality);
}

TEST(GildedRoseTest, AgedBrieSellin0Quality50) {
    vector<Item> items;
    items.emplace_back(AGED_BRIE, 0, 50);
    GildedRose app{ items };
    app.updateQuality();
    EXPECT_EQ(-1, items[0].sellIn);
    EXPECT_EQ(50, items[0].quality);
}

TEST_F(GR_Fixture, BackstagePassSellin0Quality49) {
    Item item = { BACKSTAGE_PASS, 0, 49 };
    runTest(item, -1, 0);
}

TEST_F(GR_Fixture, BackstagePassSellin10Quality0) {
    Item item = { BACKSTAGE_PASS, 10, 0 };
    runTest(item, 9, 2);
}