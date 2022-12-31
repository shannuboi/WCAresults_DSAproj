#pragma once

#include "Pair.h"

namespace my
{
	template<class type>
	type& max(type& first, type& second)
	{
		return first >= second ? first : second;
	}

	template<class type>
	type& min(type& first, type& second)
	{
		return first <= second ? first : second;
	}
}