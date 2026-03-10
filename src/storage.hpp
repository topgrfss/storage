#include "item.hpp"
#include <optional>
#include <vector>

class Storage {
    public:
	void put(const Item *item);
	std::optional<Item> get(const char *key);
	void remove(const char *key);
	int count() const;

    private:
	std::vector<Item> items_;

	std::optional<Item> is_exist_(const char *key);
};
