#pragma once

namespace my
{

template <typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;

	bool operator==(const Pair& rhs)
	{
		return first == rhs.first && second == rhs.second;
	}
	bool operator!=(const Pair& rhs)
	{
		return !(*this == rhs);
	}
};

}