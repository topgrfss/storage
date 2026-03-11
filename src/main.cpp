#include "storage.hpp"
#include <cstring>
#include <iostream>

int main()
{
	Storage str;

	std::cout << str.count() << ": items now \n";
	std::cout << "\n";

	Item item1;
	strcpy(item1.key, "key of first item");
	strcpy(item1.value, "value of first item about some thing else");

	str.put(&item1);

	std::cout << str.count() << ": items now \n";
	std::cout << "\n";

	Item item2;
	strcpy(item2.key, "key of second item");
	strcpy(item2.value, "value of second item about some thing else");

	str.put(&item2);

	std::cout << str.count() << ": items now \n";
	std::cout << "\n";

	str.remove("key of second item");

	std::cout << str.count() << ": items now \n";
	std::cout << "\n";

	str.count();
}
