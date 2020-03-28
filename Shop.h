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
	shopList.push_back(Item(90.00, "Shoes"));
	shopList.push_back(Item(130.50, "Headphones"));
}

void Shop::ReturnShopList()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	for (auto const& i : shopList)
	{
		std::cout << "Item: " << i.ReturnName() << ", value: $" << i.ReturnValue() << "\n";
	}
}

// TOOD: Come up with proper return if item does not exist in store
Item Shop::ReturnShopItem(std::string itemNameIn)
{
	auto it = std::find_if(shopList.begin(), shopList.end(), [&itemNameIn](const Item& item) { return item.ReturnName() == itemNameIn; });
	return *it;
}