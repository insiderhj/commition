#include "my_vector.h"

using namespace std;

MyVector::MyVector()
{
	length = 0;
}

MyVector::MyVector(int length)
{
	this->length = length;
	a = new double[length];
}

MyVector::~MyVector()
{
	delete[] a;
}

MyVector& MyVector::operator=(const MyVector& b)
{
	length = b.length;
	a = new double[length];
	for (int i = 0; i < length; i++) {
		a[i] = b.a[i];
	}
	return *this;
}

MyVector MyVector::operator+(const MyVector& b)
{
	MyVector res = *this;
	for (int i = 0; i < length; i++) {
		res.a[i] += b.a[i];
	}
	return res;
}

MyVector MyVector::operator-(const MyVector& b)
{
	MyVector res = *this;
	for (int i = 0; i < length; i++) {
		res.a[i] -= b.a[i];
	}
	return res;
}

MyVector MyVector::operator+(const int b)
{
	MyVector res = *this;
	for (int i = 0; i < length; i++) {
		res.a[i] += b;
	}
	return res;
}

MyVector MyVector::operator-(const int b)
{
	MyVector res = *this;
	for (int i = 0; i < length; i++) {
		res.a[i] -= b;
	}
	return res;
}

std::ostream& operator<< (std::ostream& out, MyVector& b)
{
	for (int i = 0; i < b.length; i++) {
		out << b.a[i] << ' ';
	}
	return out;
}

std::istream& operator>> (std::istream& in, MyVector& b)
{
	for (int i = 0; i < b.length; i++) {
		in >> b.a[i];
	}
	return in;
}
