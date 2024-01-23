/*Name:Uche hadassah
This project is a continuation of the fractions in slide 32
*/
#include <iostream>
using namespace std;
class Fraction
{
public:
	Fraction(); //constructor
	Fraction(int numerator, int denominator);
	int numerator(); //returns the numerator of owner object
	int denominator(); //return the denominator
	int getNumerator();
	int getDenominator();
	void assign(int n, int d); //assigns values to num and denom
	Fraction add(Fraction f); //returns the sum of the owner object and f.
	Fraction divide(Fraction f);
	Fraction mult(Fraction f);
	Fraction dif(Fraction f);
	void reduce();
private:
	int num;
	int denom;
	int gcd(int a, int b);
};
Fraction::Fraction()
{
	num = 0;
	denom = 1;
}
Fraction::Fraction(int numerator, int denominator)
{
	num = numerator;
	denom = denominator;
}
int Fraction::numerator()
{
	return num;
}
int Fraction::denominator()
{
	return denom;
}
int Fraction::getNumerator()
{
	return num;
}
int Fraction::getDenominator()
{
	return denom;
}
void Fraction::assign(int n, int d)
{
	num = n;
	denom = d;
}
Fraction Fraction::add(Fraction f)
{
	Fraction sum;
	sum.num = num * f.denom + f.num * denom;
	sum.denom = denom * f.denom;
	sum.reduce();
	return sum;
}
Fraction Fraction::dif(Fraction f)
{
	Fraction diff;
	diff.num = num * f.denom - f.num * denom;
	diff.denom = denom * f.denom;
	diff.reduce();
	return diff;
}
Fraction Fraction::mult(Fraction f)
{
	Fraction prod;
	prod.num = num * f.num;
	prod.denom = denom * f.denom;
	prod.reduce();
	return prod;
}
Fraction Fraction::divide(Fraction f)
{
	Fraction div;
	div.num = num * f.denom;
	div.denom = denom * f.num;
	div.reduce();
	return div;
}
void Fraction::reduce()
{
	int common = gcd(num, denom);
	num /= common;
	denom /= common;
}
int Fraction::gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main()
{
	Fraction fraction[4];
	// Assign values to each fraction
	fraction[0].assign(1, 2);
	fraction[1].assign(3, 4);
	fraction[2].assign(5, 6);
	fraction[3].assign(7, 8);

	// Add fractions in pairs and print the results
	Fraction result1 = fraction[0].add(fraction[1]);
	Fraction result2 = fraction[2].add(fraction[3]);
	// Print the fractions and the results of addition
	for (int i = 0; i < 4; ++i)
	{
		cout << "Fraction " << (i + 1) << ": " << fraction[i].getNumerator() << "/" << fraction[i].getDenominator() << endl;
	}

	cout << "Result of addition (1+2): " << result1.getNumerator() << "/" << result1.getDenominator() << endl;
	cout << "Result of addition (3+4): " << result2.getNumerator() << "/" << result2.getDenominator() << endl;

	return 0;
}
