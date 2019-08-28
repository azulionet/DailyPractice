#pragma once
class Day0028
{
public:
	Day0028();
	~Day0028();
};

#include <optional>




template<typename T>
struct Nullable
{

	operator T()
	{
		return {};
	}


	std::optional<int> a;

};

