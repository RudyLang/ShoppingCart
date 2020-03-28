class Shop 
{
private:
	std::list<Item> shopList; 

public:
	Shop();
	void ReturnShopList();
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