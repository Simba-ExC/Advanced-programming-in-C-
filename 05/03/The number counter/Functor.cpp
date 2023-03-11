#include "Functor.h"

Functor::Functor() : _sum(0), _count(0)
{
}

void Functor::operator()(std::vector<int> v)
{
	if (!v.empty())
	{
		_sum = 0;
		_count = 0;
		for (const int& data : v)
		{
			if (!(data % 3))
			{
				_sum += data;
				++_count;
			}
		}
	}
}

int Functor::get_sum()
{
	return _sum;
}

int Functor::get_count()
{
	return _count;
}
