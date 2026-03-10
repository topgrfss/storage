#include "storage.hpp"
#include <optional>

void Storage::put(const Item *item)
{
	if (is_exist_((*item).key)) {
	}
}

std::optional<Item> Storage::get(const char *key)
{
	Item item;

	if (is_exist_(key)) {
		return item;
	}
	return item;
}

void Storage::remove(const char *key)
{
	if (is_exist_(key)) {
	}
}

int Storage::count() const
{
	return items_.size();
}

std::optional<Item> Storage::is_exist_(const char *key)
{
	Item item;
	return item;

	return std::nullopt;
}
