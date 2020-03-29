#include "pch.h"
#include <iostream>
#include "Cart.h"
#include "Shop.h"

int main()
{
	Shop shop;
	std::cout << "STORE FRONT" << "\n";
	shop.ReturnShopList();
	std::cout << "\n";

	std::string selectedItem;
	size_t selectedQuantity;
	std::cout << "Enter name of item to add to cart: ";
	std::cin >> selectedItem;
	std::cout << "Enter the quantity that you wish to purchase: ";
	std::cin >> selectedQuantity; //TODO: Handle user entering anything other than uint

	// Check the shop for enter item and quanity.
	// If the item and quantity are valid, simply add it to the user's cart.
	// Else, throw an error to the user.
	Cart userCart;
	Item chosenItem = shop.ReturnShopItem(selectedItem);
	if (chosenItem.ReturnName() == "")
	{
		std::cout << "This item is not in the store!" << "\n";
	}
	else
	{
		userCart.AddItem(selectedQuantity, shop.ReturnShopItem(selectedItem));
	}

	std::cout << "\n";

	std::cout << "YOUR CART" << "\n";
	userCart.ReturnAllItems();

	return 0;
}
