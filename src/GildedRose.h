#include <string>
#include <vector>
#include <algorithm>

class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string const& name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    std::vector<Item> & items;
    explicit GildedRose(std::vector<Item> & items);
    
    void updateQuality();
};

