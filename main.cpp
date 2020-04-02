#include "pch.h"
#include <iostream>
#include <limits>
#include "Cart.h"
#include "Shop.h"
#include "Helpers.h"

void Shopping()
{
	char choice;
	bool run = true;

	while (run)
	{
		Shop shop;
		std::cout << "STORE FRONT" << "\n";
		shop.ReturnShopList();
		std::cout << "\n";

		std::string selectedItem;
		uint8_t selectedQuantity;

		std::cout << "Enter name of item to add to cart: ";
		std::cin >> selectedItem;

		while (1)
		{
			if (!helpers::IsAlpha(selectedItem))
			{
				std::cin.clear();
				std::cout << "You did not enter a valid name, please try again: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> selectedItem;
			}
			else
			{
				break;
			}
		}
		
		std::cout << "Enter the quantity that you wish to purchase: ";
		std::cin >> selectedQuantity; //TODO: Handle user entering anything other than uint

		while (1)
		{
			if (!helpers::isNumeric(std::to_string(selectedQuantity)))
			{
				std::cin.clear();
				std::cout << "You did not enter a valid number, please try again: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> selectedQuantity;
			}
			else
			{
				break;
			}
		}

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

		std::cout << "\n";
		std::cout << "Would you like to checkout? (y/n): ";
		std::cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			run = false;
		}
	}
}


int main()
{
	Shopping();
	// Return receipt here

	return 0;
}
