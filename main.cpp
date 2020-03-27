//#include "pch.h"
#include <iostream>
#include "Cart.h"

int main()
{
	Cart userCart;
	Item item1(90.00, "Shoes");
	Item item2(130.50, "Headphones");

	userCart.AddItem(1, item1);
	userCart.AddItem(2, item2);
	userCart.AddItem(1, item1);
	userCart.ReturnAllItems();

	return 0;
}
