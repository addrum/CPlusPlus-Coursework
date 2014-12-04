#ifndef FRACTION_H
#define FRACTION_H

class fraction {
	public:
		fraction();
		fraction(int n);
		fraction(int n, int m);
		operator double() const {double dbl = numerator; dbl = dbl/static_cast<double>(denominator); return dbl;}
		int getNumerator() const;
		int getDenominator() const;
		void setNumerator(const int n);
		void setDenominator(const int d);
		int lcm( int n, int m);
		int gcd( int n, int m);
		bool operator==(const fraction &o);
		bool operator!=(const fraction &o);
		bool operator<(const fraction &o);
		bool operator>(const fraction &o);
		bool operator<=(const fraction &o);
		bool operator>=(const fraction &o);
		fraction operator+=(const fraction &o);
		fraction operator-=(const fraction &o);
		fraction operator*=(const fraction &o);
		fraction operator/=(const fraction &o);

	private:
		int numerator;
		int denominator;
};

#endif // FRACTION_H