//by having constructor(s) with arguments only(so without the empty constructor), user is forced to enter parameters.

#include "fraction.h"
#include "samplet.cc"
#include "sample.h"
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <string>
#include <sstream>
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
	fraction newFraction;
	newFraction.setNumerator(a);
	return b+=a;
}

fraction operator+(fraction a, int b)
{
	fraction newFraction;
	newFraction.setNumerator(b);
	return a+=b;
}

fraction operator-(fraction a, fraction b)
{
	return a-=b;
}

fraction operator-(int a, fraction b)
{
	fraction newFraction;
	newFraction.setNumerator(a);
	return b-=a;
}

fraction operator-(fraction a, int b)
{
	fraction newFraction;
	newFraction.setNumerator(b);
	return a-=b;
}

fraction operator*(fraction a, fraction b)
{
	return a*=b;
}

fraction operator*(int a, fraction b)
{
	fraction newFraction;
	newFraction.setNumerator(a);
	return b*=a;
}

fraction operator*(fraction a, int b)
{
	fraction newFraction;
	newFraction.setNumerator(b);
	return a*=b;
}

fraction operator/(fraction a, fraction b)
{
	return a/=b;
}

fraction operator/(int a, fraction b)
{
	fraction newFraction;
	newFraction.setNumerator(a);
	return b/=a;
}

fraction operator/(fraction a, int b)
{
	fraction newFraction;
	newFraction.setNumerator(b);
	return a/=b;
}

ostream & operator<<( ostream &os, const fraction &o)
{
	os << o.getNumerator() << "/" << o.getDenominator();
	return os;
}

istream & operator>>( istream &os, fraction &f)
{
	int num, denom = 1;
	char c1;
	os >> num;
	f.setNumerator(num);
	if(os >> c1 >> denom && c1 == '/'){
			f.setDenominator(denom);
	}else{
		f.setDenominator(1);
	}
	return os;
}

template <class any> istream & operator>>( istream &os, samplet<any> &f)
{
	vector<any> vectoria;
	int number;
	any nextNumber;
	char c1, c2;
		if (os >> c1 >> number >> c2 && c1 == '<' && c2 == ':'){
			for (int i=0;i<number;i++){
				if (os >> nextNumber){
					vectoria.push_back(nextNumber);
				}
			}
			if (os >> c1 && c1 == '>'){
				f.set_data(vectoria);
			}
		}
	return os;
}

istream & operator>>( istream &os, sample &f)
{
	vector<double> vectoria;
	int number;
	double nextNumber;
	char c1, c2;
		if (os >> c1 >> number >> c2 && c1 == '<' && c2 == ':'){
			for (int i=0;i<number;i++){
				if (os >> nextNumber){
					vectoria.push_back(nextNumber);
					/*
					
					The output is not correct. There are 2 problems associated with the output:
					1. The code rounds up the number to 5 d.p., e.g. 1.7976931348623158e+308 to 1.79769e+308.
					2. The code is not able to calculate these numbers as they are too large for it to read and calculate.
					So it gives the following output for input <2: 1.7976931348623158e+308 1.7976931348623158e+308 >:
					<2:1.79769e+308 1.79769e+308 >
					1.79769e+308
					1.79769e+308
					0
					inf
					inf
					inf
					inf
					inf
					
					How did I fix it?
					I have now made the changes to the samplet.h file so that it divides first,
					then sums up the division outcomes. Before it was other way around.
					It fixed the output problem 2 (discussed above).
					So the new outcome for the same input is:
					<2:1.79769e+308 1.79769e+308 >
					1.79769e+308
					1.79769e+308
					0
					1.79769e+308
					1.79769e+308
					1.79769e+308
					0
					0
					
					*/
				}
			}
			if (os >> c1 && c1 == '>'){
				f.set_data(vectoria);
			}
		}else{
			if (cin.bad()) cerr << "\nBad input\n\n";
		}
	return os;
}

template <class any> ostream & operator<<( ostream &os, samplet<any> &o)
{
	int a = 0;
	
	os << "< " << o.get_data().size() << ": ";
	while(a < o.get_data().size()){
		os << o.get_data()[a] << " ";
		a++;
	}
	os << ">";
	return os;
}

ostream & operator<<( ostream &os, sample &o)
{
	double a = 0;
	
	os << "< " << o.get_data().size() << ": ";
	while(a < o.get_data().size()){
		os << o.get_data()[a] << " ";
		a++;
	}
	os << ">";
	return os;
}

int main ()
{
	sample s;
	while (cin  >> s){
		cout	<< s					<< endl
				<< s.minimum()		<< endl		<< s.maximum()		<< endl
				<< s.range()			<< endl		<< s.midRange()		<< endl
				<< s.median()		<< endl		<< s.mean()			<< endl
				<< s.variance()		<< endl		<< s.std_deviation() << endl
				;
	}
	
	if (cin.bad()) cerr << "\nBad input\n\n";
	return(0); 
}