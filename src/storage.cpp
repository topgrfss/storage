#include "storage.hpp"

#include <cstddef>
#include <cstring>
#include <iostream>
#include <optional>
#include <strings.h>

void Storage::put(const Item *item)
{
	Item *existing_item = find_item((*item).key);

	if (existing_item != nullptr) {
		std::strncpy(existing_item->value, (*item).value,
			     sizeof(existing_item->value) - 1);
		existing_item->value[sizeof(existing_item->value) - 1] = '\0';
		return;
	}
	items_.push_back(*item);
}

std::optional<Item> Storage::get(const char *key)
{
	Item *item_to_find = find_item(key);

	if (item_to_find == nullptr)
		return std::nullopt;
	return *item_to_find;
}

void Storage::remove(const char *key)
{
	Item *item_to_remove = find_item(key);
	if (!item_to_remove)
		return;

	size_t ind = item_to_remove - items_.data();

	if (ind != items_.size() - 1) {
		items_[ind] = items_.back();
	}

	items_.pop_back();
}

int Storage::count() const
{
	for (size_t i = 0; items_.size() > i; ++i) {
		std::cout << "Value: " << items_[i].value << "\n";
		std::cout << "Key: " << items_[i].key << "\n";
	}
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
