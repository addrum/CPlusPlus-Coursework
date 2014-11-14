#include "fraction.h"
#include <iostream>
#include <stdlib.h>
#include <utility>
using namespace std;

// test variables
fraction fractionA(3,5);
fraction fractionB(-3,25);
fraction fractionC(2, 255);

fraction operator+(fraction a, fraction b)
{
	return a+=b;
}

fraction operator+(int a, fraction b)
{
	fraction newFraction(a);
	return b+=a;
}

fraction operator+(fraction a, int b)
{
	fraction newFraction(b);
	return a+=b;
}

fraction operator-(fraction a, fraction b)
{
	return a-=b;
}

fraction operator-(int a, fraction b)
{
	fraction newFraction(a);
	return b-=a;
}

fraction operator-(fraction a, int b)
{
	fraction newFraction(b);
	return a-=b;
}

fraction operator*(fraction a, fraction b)
{
	return a*=b;
}

fraction operator*(int a, fraction b)
{
	fraction newFraction(a);
	return b*=a;
}

fraction operator*(fraction a, int b)
{
	fraction newFraction(b);
	return a*=b;
}

fraction operator/(fraction a, fraction b)
{
	return a/=b;
}

fraction operator/(int a, fraction b)
{
	fraction newFraction(a);
	return b/=a;
}

fraction operator/(fraction a, int b)
{
	fraction newFraction(b);
	return a/=b;
}

ostream & operator<<( ostream &os, const fraction &o)
{
	os << o.getNumerator() << "/" << o.getDenominator();
	return os;
}

istream & operator>>( istream &os, fraction &f)
{
	string s;
	os >> s;
    string delim = "/";
    auto start = 0U;
    auto end = s.find(delim);
	f.setNumerator(stoi(s.substr(start, end - start)));
	f.setDenominator(stoi(s.substr(end + 1, s.find(1U, start))));
    return os;
}

int main ()
{
	// test operations
	fraction newFraction;
	fraction fB;
	newFraction = fractionA+fractionB;
	cin >> fB;
	cout << fB << endl;
	cout << newFraction << endl;
}