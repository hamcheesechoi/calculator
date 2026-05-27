#pragma once
#include <string>
#include <vector>
#define interface struct

interface GildedRoseItem{
    virtual void updateQuality() = 0;
};

class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name{ name }, sellIn{ sellIn }, quality{ quality }
    {
    }
};

class GildedRose
{
public:
    std::vector<Item>& items;
    GildedRose(std::vector<Item>& items);

    void updateQuality();
private:
    void updateQuality(Item& item);
    void updateSellIn(Item& item);

    GildedRoseItem* getGildedRoseItem(Item& item);
};
