/*Adding to the fraction class on slide 32:
a) Provide an additional, second constructor for the fraction object that initializes the
numerator and denominator to some given values.
b) Add the following functions to the fraction object:
? divide – returns the quotient of two fractions
? mult – returns the product
? dif – returns the difference
c) Write a public function reduce that reduces the fraction to its simplest form. E.g.
6/8 should be reduced to 3/4. (To reduce a fraction you divide both the numerator
and the denominator by the greatest common divisor. You will need the gcd
function we provided earlier in the course. This should also be a private
function).
d) Declare an array of 4 fraction objects, assign values to the data members of each
one and perform the addition in pairs: first with second, third with fourth. Print
the 4 fractions, along with the resulting additions.
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
