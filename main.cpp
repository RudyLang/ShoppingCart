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
	std::cin >> selectedQuantity;

	// Check item in shop, if it's there, return it
	Cart userCart;
	userCart.AddItem(selectedQuantity, shop.ReturnShopItem(selectedItem));

	std::cout << "\n";

	std::cout << "YOUR CART" << "\n";
	userCart.ReturnAllItems();

	return 0;
}
