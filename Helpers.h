#include <string>

namespace helpers
{
	bool IsAlpha(std::string& stringIn)
	{
		for (char& c : stringIn)
		{
			// Account for lower and upper case ASCII characters
			// A-Z -> 65-90
			// a-z -> 97-122
			if ((int)(c) < 65 || (int)(c) > 122 || (int)(c) == 91 || (int)(c) == 92 || (int)(c) == 93 || (int)(c) == 94 || (int)(c) == 95 )
			{
				return false;
			}
		}
		return true;
	}

	bool isNumeric(std::string stringIn)
	{
		for (char& c : stringIn)
		{
			// Accound for ASCII characters that are numbers only
			// 0-9 -> 48-57
			if ((int)(c) < 47 || (int)(c) > 58)
			{
				return false;
			}
		}
		return true;
	}
}