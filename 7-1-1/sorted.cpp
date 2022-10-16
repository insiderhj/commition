#include <algorithm>
#include "sorted.h"

using namespace std;

SortedArray::SortedArray() {}

SortedArray::~SortedArray() {}

void SortedArray::AddNumber(int num)
{
	numbers_.push_back(num);
}

std::vector<int> SortedArray::GetSortedAscending()
{
	vector<int> v = numbers_;
	sort(v.begin(), v.end());
	return v;
}

std::vector<int> SortedArray::GetSortedDescending()
{
	vector<int> v = numbers_;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	return v;
}

int SortedArray::GetMax()
{
	return *max_element(numbers_.begin(), numbers_.end());
}

int SortedArray::GetMin()
{
	return *min_element(numbers_.begin(), numbers_.end());
}
