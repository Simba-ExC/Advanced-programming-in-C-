#pragma once

#include <vector>

class Functor
{
private:
	int _sum;
	int _count;
public:
	Functor();

	void operator() (std::vector<int> v);
	int get_sum();
	int get_count();
};