#pragma once

#include "Pair.h"

namespace my
{
	template<class type>
	type max(type first, type second)
	{
		return first >= second ? first : second;
	}

	template<class type>
	type min(type first, type second)
	{
		return first <= second ? first : second;
	}

	// Container must have GetLenght() and operator[] methods (must be random access container)
	template <class RAContainer>
	void printRAContainer(const RAContainer& cont)
	{
		for (int i = 0; i < cont.GetLength(); i++)
		{
			std::cout << cont[i] << " ";
		}
		std::cout << std::endl;
	}
}