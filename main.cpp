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

	Cart userCart;
	Item item1(90.00, "Shoes");
	Item item2(130.50, "Headphones");

	userCart.AddItem(1, item1);
	userCart.AddItem(2, item2);
	userCart.AddItem(2, item1);
	std::cout << "\n";

	std::cout << "YOUR CART" << "\n";
	userCart.ReturnAllItems();

	return 0;
}
