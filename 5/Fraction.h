#pragma once
#include <string>
using namespace std;

class Fraction
{
private:
	int numerator; //the "top" of the fraction
	int denominator; //the "bottom" of the fraction

	// PRE:
	// POST: Fraction is simplified, e.g. 3/9, simplifies to 1/3
	void simplify();

	// PRE:
	// POST: Returns the greatest common divisor of a and b
	int gcd(int a, int b)const;

	// Friend functions
	// ...
	friend ostream& operator<<(ostream & os, const Fraction & f);

public:
	// Constructors and Destructor
	Fraction(void);
	Fraction(int n, int d);
	~Fraction(void);
	
	// Overloaded operators
	// +, -, *, and /
	Fraction operator+(const Fraction & f) const;
	Fraction operator-(const Fraction & f) const;
	Fraction operator*(const Fraction & f) const;
	Fraction operator/(const Fraction & f) const;
};


