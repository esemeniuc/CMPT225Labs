#include <iostream>
#include "Fraction.h"

using namespace std;

// Default constructor
Fraction::Fraction(void)
{
	numerator = 0;
	denominator = 1;
}

// Constructor
Fraction::Fraction(int n, int d)
{
	if (d == 0){
		denominator = 1;
		numerator = 0;
	}else if (d < 0){
		denominator = d * -1;
		if (n > 0){
			numerator = n * -1;
		}
	}else{
		numerator = n;
		denominator = d;
	}
}

Fraction::~Fraction(void)
{
	//empty
}

// Returns the greatest common divisor of two integers
int Fraction::gcd(int a, int b)const{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Simplifies the calling fraction
void Fraction::simplify(){
	int factor = gcd(numerator, denominator);
	numerator = numerator / factor;
	denominator = denominator / factor;
}

// Overloaded Operators
/*
 * In each case: (num1/den1) op (num2/den2)
 *
 * PLUS OPERATOR
 * result = (num1 * den2 + num2 * den1) / (den1 * den2)
 *
 * MINUS OPERATOR
 * result = (num1 * den2 - num2 * den1) / (den1 * den2)
 *
 * MULTIPLICATION OPERATOR
 * result = (num1 * num2) / (den1 * den2)
 *
 * DIVISION OPERATOR
 * result = (num1 * den2) / (den1 * num2)
 */
Fraction Fraction::operator+(const Fraction & f) const
{
	Fraction result((numerator * f.denominator + f.numerator * denominator), (denominator * f.denominator));
	result.simplify();
	return result;
}

Fraction Fraction::operator-(const Fraction & f) const
{
	Fraction result((numerator * f.denominator - f.numerator * denominator), (denominator * f.denominator));
	result.simplify();
	return result;
}

Fraction Fraction::operator*(const Fraction & f) const
{
	Fraction result((numerator * f.numerator), (denominator * f.denominator));
	result.simplify();
	return result;
}

Fraction Fraction::operator/(const Fraction & f) const
{
	Fraction result((numerator * f.denominator), (denominator * f.numerator));
	result.simplify();
	return result;
}

ostream& operator<<(ostream & os, const Fraction & f)
{
	os << f.numerator << "/" << f.denominator;
	return os;
}