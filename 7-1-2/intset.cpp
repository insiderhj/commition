#include <vector>
#include <algorithm>
#include "intset.h"

using namespace std;

IntegerSet::IntegerSet() {}

IntegerSet::~IntegerSet() {}

void IntegerSet::AddNumber(int num)
{
	if (count(numbers_.begin(), numbers_.end(), num))
		return;
	numbers_.push_back(num);
	sort(numbers_.begin(), numbers_.end());
}

void IntegerSet::DeleteNumber(int num)
{
	numbers_.erase(find(numbers_.begin(), numbers_.end(), num));
}

int IntegerSet::GetItem(int pos)
{
	if (pos < 0 || numbers_.size() <= pos)
		return -1;
	return numbers_.at(pos);
}

std::vector<int> IntegerSet::GetAll()
{
	vector<int> v = numbers_;
	return v;
}