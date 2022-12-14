#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{}

void updateItemConjuredQuality(Item& item) //EXTRACT METHOD
{
    if (item.name == "Conjured"){
        item.quality = item.quality - 1;
    }
}
    
void updateItemQuality(Item& item){ //EXTRACT METHOD
    if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert"
    && item.quality > 0 && item.name != "Sulfuras, Hand of Ragnaros")
    {
        item.quality = item.quality - 1;

        updateItemConjuredQuality(item);
    }
    else
    {
        if (item.quality < 50)
        {
            item.quality = item.quality + 1;

            if (item.name == "Backstage passes to a TAFKAL80ETC concert")
            {
                item.quality = (item.sellIn < 11) ? item.quality+1:item.quality;
                item.quality = (item.sellIn < 6) ? item.quality+1:item.quality;
            }
        }
    }

    if (item.name != "Sulfuras, Hand of Ragnaros")
    {
        item.sellIn = item.sellIn - 1;
    }

    if (item.sellIn < 0)
    {
        if (item.name != "Aged Brie")
        {
            item.quality = (item.name != "Backstage passes to a TAFKAL80ETC concert"
                && item.quality > 0 
                && item.name != "Sulfuras, Hand of Ragnaros") ? item.quality - 1:0;
        }
        else if (item.quality < 50)
        {
            item.quality = item.quality + 1;
        }
    }
}

void GildedRose::updateQuality() 
{
    std::for_each(items.begin(), items.end(), updateItemQuality);
}
