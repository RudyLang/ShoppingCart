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

	// Instantiate our shop and cart classes
	Shop shop;
	Cart userCart;

	while (run)
	{
		// Print Shop Inventory
		std::cout << "STORE FRONT" << "\n";
		shop.ReturnShopList();
		std::cout << "\n";

		// Initialize input parameters
		std::string selectedItem = "";
		int selectedQuantity = 0;

		// Clear input
		std::cin.clear();

		// Request user to enter exact name of item
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
		
		// Clear input
		std::cin.clear();

		// Request user to enter quantity of item
		std::cout << "Enter the quantity that you wish to purchase: ";
		std::cin >> selectedQuantity;

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

	// Print Receipt
	std::cout << "\n";
	std::cout << "YOUR RECEIPT" << "\n";
	userCart.CheckOut();
}


int main()
{
	Shopping();
	// Return receipt here

	return 0;
}
