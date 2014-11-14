#include "fraction.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

fraction::fraction()
{
	
}

fraction::fraction(int n)
:	numerator(n),
	denominator(1)
{
}

fraction::fraction(int n, int m)
{
	if(m==0){
		numerator = 0;
		denominator = 0;
	}else if(m<0){
		numerator = -n;
		denominator = -m;
	}else{
		numerator = n;
		denominator = m;
	}
}

int fraction::gcd( int n, int m){
	int gcdVal = 0;
	for(int i = 1; i <= abs(n) && i <= abs(m); i++){
		if(n % i == 0 && abs(m) % i == 0 ){
			gcdVal=i;
		}
	}
	return abs(gcdVal);
}

int fraction::lcm( int n, int m){
	return abs(m * (n / gcd(n, m)));
}

int fraction::getNumerator() const
{	
	return numerator;
}

int fraction::getDenominator() const
{
	return denominator;
}

void fraction::setNumerator(const int n)
{
	numerator = n;
}

void fraction::setDenominator(const int n)
{
	denominator = n;
}

fraction &fraction::operator+=(const fraction &o)
{
	fraction newFraction;
	
	int a = getNumerator() * o.getDenominator();
	int b = o.getNumerator() * getDenominator();
	int c = o.getDenominator() * getDenominator();
	int d = a+b;
	int e = gcd(d,c);

	newFraction.setNumerator(d/e);
	newFraction.setDenominator(c/e);

	return newFraction;
}

fraction &fraction::operator-=(const fraction &o)
{
	fraction newFraction;
	
	int a = getNumerator() * o.getDenominator();
	int b = o.getNumerator() * getDenominator();
	int c = o.getDenominator() * getDenominator();
	int d = a-b;
	int e = gcd(d,c);

	newFraction.setNumerator(d/e);
	newFraction.setDenominator(c/e);

	return newFraction;
}

fraction &fraction::operator*=(const fraction &o)
{
	fraction newFraction;
	
	int a = getNumerator() * o.getNumerator();
	int b = getDenominator() * o.getDenominator();
	int c = gcd(a,b);
	newFraction.setNumerator(a/c);
	newFraction.setDenominator(b/c);

	return newFraction;
}

fraction &fraction::operator/=(const fraction &o)
{
	fraction newFraction;
	int check = 1;
	if(o.getNumerator()<0){
		check = -1;
	}
	int a = getNumerator() * o.getDenominator();
	int b = getDenominator() * o.getNumerator();
	int c = gcd(a,b);

	newFraction.setNumerator(check*a/c);
	newFraction.setDenominator(check*b/c);

    return newFraction;
}

bool fraction::operator==(const fraction &o)
{
	fraction a(numerator, denominator);
	a = a/=o;
	if(a.getNumerator() == 1 && a.getNumerator() == 1){
		return true;
	}else{
		return false;
	}
}

bool fraction::operator!=(const fraction &o)
{
	fraction a(numerator, denominator);
	a = a/=o;
	if(a.getNumerator() == 1 && a.getNumerator() == 1){
		return false;
	}else{
		return true;
	}
}

bool fraction::operator<(const fraction &o){
	double num1 = getNumerator();
	double den1 = getDenominator();
	double num2 = o.getNumerator();
	double den2 = o.getDenominator();
	return num1/den1 < num2/den2;
}

bool fraction::operator>(const fraction &o){
	double num1 = getNumerator();
	double den1 = getDenominator();
	double num2 = o.getNumerator();
	double den2 = o.getDenominator();
	return num1/den1 > num2/den2;
}

bool fraction::operator<=(const fraction &o){
	double num1 = getNumerator();
	double den1 = getDenominator();
	double num2 = o.getNumerator();
	double den2 = o.getDenominator();
	return num1/den1 <= num2/den2;
}

bool fraction::operator>=(const fraction &o){
	double num1 = getNumerator();
	double den1 = getDenominator();
	double num2 = o.getNumerator();
	double den2 = o.getDenominator();
	return num1/den1 >= num2/den2;
}