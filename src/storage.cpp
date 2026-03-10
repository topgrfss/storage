#include "storage.hpp"

#include <algorithm>
#include <cstring>
#include <optional>

// todo
//
//
//

void Storage::put(const Item *item)
{
}

std::optional<Item> Storage::get(const char *key)
{
}

void Storage::remove(const char *key)
{
}

int Storage::count() const
{
	return items_.size();
}

Item *Storage::find_item(const char *key)
{
}
