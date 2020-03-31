#include "Item.h"
#include <list>
#include <iomanip>
#include <algorithm>

class Cart
{
private:
	uint8_t size;
	uint8_t items;

	std::list<std::pair<uint8_t, Item>> contents; // List of pairs. First value of pair specifies item quantity

public:
	Cart();
	void AddItem(uint8_t quantityIn, Item itemIn);
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
void Cart::AddItem(uint8_t quantityIn, Item itemIn)
{
	// Using std::find_if algorithm with overloaded operator == for Item class
	// Checks to see if the second property of the pair matches the item being added; disregards quantity at this point
	auto it = std::find_if(contents.begin(), contents.end(), [&itemIn](const std::pair<uint8_t, Item>& p) { return p.second == itemIn; });

	// If iterator points to the end of the list then the item doesn't exist, add to end of list
	// Else, increment value where iterator points
	if (it == contents.end())
	{
		std::pair<size_t, Item> newItem(quantityIn, itemIn);
		contents.push_back(newItem);
		std::cout << std::to_string(quantityIn) << " " << itemIn.ReturnName() << " added to cart." << "\n";
	}
	else
	{
		it->first += quantityIn;
		std::cout << std::to_string(quantityIn) << " " << itemIn.ReturnName() << " added to cart." << "\n";
	}
}

void Cart::ReturnAllItems()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	// If the cart is empty, tell the user.
	// Else, iterate through and print it's contents.
	if (contents.empty())
	{
		std::cout << "Nothing in your cart!" << "\n";
	}
	else
	{
		for (auto const& i : contents)
		{
			std::cout << "Item: " << i.second.ReturnName() << ", Value: $" << i.second.ReturnValue() << ", Quantity: " << i.first << "\n";
		}
	}
}

/*Cart::~Cart()
{
	std::cout << "Delete Cart";
}*/