#include "Item.h"
#include <list>
#include <iomanip>
#include <algorithm>

class Cart
{
private:
	int size;
	int items;
	float total;

	std::list<std::pair<int, Item>> contents; // List of pairs. First value of pair specifies item quantity

public:
	Cart();
	void AddItem(int quantityIn, Item itemIn);
	void ReturnAllItems();
	float CalculateTotal();
	void CheckOut();
	void EmptyCart();
	//~Cart();
};

Cart::Cart()
{
	size = 10;
	items = 0;
	total = 0.0;
}

// Using 'quantity to stack multiple items in cart
// Need to increment quantity
// How can we search for items in the cart?
void Cart::AddItem(int quantityIn, Item itemIn)
{
	// Using std::find_if algorithm with overloaded operator == for Item class
	// Checks to see if the second property of the pair matches the item being added; disregards quantity at this point
	auto it = std::find_if(contents.begin(), contents.end(), [&itemIn](const std::pair<int, Item>& p) { return p.second == itemIn; });

	// If iterator points to the end of the list then the item doesn't exist, add to end of list
	// Else, increment value where iterator points
	if (it == contents.end())
	{
		std::pair<int, Item> newItem(quantityIn, itemIn);
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

float Cart::CalculateTotal()
{
	total = 0.0;

	for (auto const& i : contents)
	{
		total += i.second.ReturnValue() * i.first; // Value of item multiplied by it's quantity, summed
	}

	return total;
}

void Cart::CheckOut()
{
	ReturnAllItems();

	std::cout << "Your total is: $" << CalculateTotal() << "\n";
}

void Cart::EmptyCart()
{
	contents.clear();
	std::cout << "Cart Emptied" << "\n";
}

/*Cart::~Cart()
{
	std::cout << "Delete Cart";
}*/