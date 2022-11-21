#include "my_string2.h"

using namespace std;

MyString2::MyString2(const MyString2& b)
{
	str = b.str;
}

MyString2 MyString2::operator+(const MyString2& b)
{
	MyString2 res(*this);
	res.str += b.str;
	return res;
}

MyString2 MyString2::operator*(const int b)
{
	MyString2 res(*this);
	res.str = "";
	for (int i = 0; i < b; i++) {
		res.str += str;
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, MyString2& my_string)
{
	out << my_string.str;
	return out;
}

std::istream& operator>>(std::istream& in, MyString2& my_string)
{
	in >> my_string.str;
	return in;
}
