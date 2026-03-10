#include "storage.hpp"

#include <cstring>
#include <optional>

void Storage::put(const Item *item)
{
	Item *item_to_find = find_item((*item).key);

	if (item_to_find != nullptr) {
		std::strncpy(item_to_find->value, (*item).value,
			     sizeof(item_to_find->value) - 1);
		item_to_find->value[sizeof(item_to_find->value) - 1] = '\0';
		return;
	}
	items_.push_back(*item_to_find);
}

std::optional<Item> Storage::get(const char *key)
{
	return *find_item(key);
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
	for (Item &item : items_) {
		if (std::strcmp(item.key, key) == 0) {
			return &item;
		}
	}
	return nullptr;
}
