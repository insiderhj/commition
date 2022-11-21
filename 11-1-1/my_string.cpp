#include "my_string.h"

using namespace std;

MyString& MyString::operator=(const MyString& b)
{
	str = b.str;
	return *this;
}

MyString MyString::operator+(const MyString& b)
{
	MyString res;
	res.str = str + b.str;
	return res;
}

MyString MyString::operator*(const int b)
{
	MyString res;
	res.str = "";
	for (int i = 0; i < b; i++) {
		res.str += str;
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, MyString& my_string)
{
	out << my_string.str;
	return out;
}

std::istream& operator>>(std::istream& in, MyString& my_string)
{
	in >> my_string.str;
	return in;
}
