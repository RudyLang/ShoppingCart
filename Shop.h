class Shop 
{
private:
	std::list<Item> shopList; 

public:
	Shop();
	void ReturnShopList();
	Item ReturnShopItem(std::string itemIn);
};

Shop::Shop()
{
	shopList.push_back(Item(90.00, "Sword"));
	shopList.push_back(Item(130.50, "Shield"));
	shopList.push_back(Item(50.20, "Helmet"));
	shopList.push_back(Item(30.50, "Robe"));
	shopList.push_back(Item(80.70, "Wand"));
}

void Shop::ReturnShopList()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	for (auto const& i : shopList)
	{
		std::cout << "Item: " << i.ReturnName() << ", Value: $" << i.ReturnValue() << "\n";
	}
}

// If item exists, return a reference to that item.
// If it does not exist, return an empty item.
Item Shop::ReturnShopItem(std::string itemNameIn)
{
	auto it = std::find_if(shopList.begin(), shopList.end(), [&itemNameIn](const Item& item) { return item.ReturnName() == itemNameIn; });

	if (it == shopList.end())
	{
		Item emptyItem;
		return emptyItem;
	}
	else
	{
		return *it;
	}
}