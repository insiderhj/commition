#include <algorithm>
#include "message.h"

using namespace std;

MessageBook::MessageBook() {}

MessageBook::~MessageBook() {}

void MessageBook::AddMessage(int number, const std::string& message)
{
	if (messages_.find(number) != messages_.end())
		messages_.erase(number);
	messages_.insert({number, message});
}

void MessageBook::DeleteMessage(int number)
{
	messages_.erase(number);
}

std::vector<int> MessageBook::GetNumbers()
{
	vector<int> v;
	for (auto i : messages_)
		v.push_back(i.first);
	return v;
}

const std::string& MessageBook::GetMessage(int number)
{
	return messages_.find(number)->second;
}
