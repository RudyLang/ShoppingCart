#include <string>

class Item
{
private:
	float value;
	std::string name;

public:
	Item();
	Item(float valueIn, std::string nameIn);
	float ReturnValue() const;
	std::string ReturnName() const; // Cannot call a non-const method with a const object, so we make this const. Getters should be const anyway.
	friend bool operator== (const Item &i1, const Item &i2); // 'friend' allows us to access private members of this class
};

Item::Item()
{
	value = 0;
	name = "";
}

Item::Item(float valueIn, std::string nameIn)
{
	value = valueIn;
	name = nameIn;
}

float Item::ReturnValue() const
{
	return value;
}

std::string Item::ReturnName() const
{
	return name;
}
bool operator== (const Item &i1, const Item &i2)
{
	return i1.name == i2.name;
}
