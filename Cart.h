#include "Item.h"
#include <list>
#include <iomanip>
#include <algorithm>

class Cart
{
private:
	std::size_t size;
	std::size_t items;

	std::list<std::pair<std::size_t, Item>> contents; // List of pairs. First value pair specifies item quantity

public:
	Cart();
	void AddItem(size_t quantityIn, Item itemIn);
	void ReturnAllItems();
	//~Cart();
};

Cart::Cart()
{
	size = 10;
	items = 0;
}

// Using 'quantity to stack multiple items in cart
// Need to increment quantity
// How can we search for items in the cart?
void Cart::AddItem(size_t quantityIn, Item itemIn)
{
	// Using std::find_if algorithm with overloaded operator == for Item class
	// I had to get fancy with find_if in order to search through the pairs
	auto it = std::find_if(contents.begin(), contents.end(), [&itemIn](const std::pair<std::size_t, Item>& p) { return p.second == itemIn; });

	if (it == contents.end()) // If iterator points to the end of the list then the item doesn't exist -> add as is
	{
		std::pair<size_t, Item> newItem(quantityIn, itemIn);
		contents.push_back(newItem);
	}
	else
	{
		it->first++; // This is dumb right now, need to incoming quantity and add that
	}
}

void Cart::ReturnAllItems()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	for (auto const& i : contents)
	{
		std::cout << "Item: " << i.second.ReturnName() << ", value: $" << i.second.ReturnValue() << ", Quantity: " << i.first << "\n";
	}
}

/*Cart::~Cart()
{
	std::cout << "Delete Cart";
}*/