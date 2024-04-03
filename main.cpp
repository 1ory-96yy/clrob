#include <iostream>

class Fraction
{
public:
    int numerator;
    int denominator;

public:
    const Fraction& getBigger(const Fraction& other) {
        if (this->denominator == other.denominator) {
            return this->numerator > other.numerator ? *this : other;
        }
        else {
            int commonDenominator = this->denominator * other.denominator;
            int thisNumerator = this->numerator * (commonDenominator / this->denominator);
            int otherNumerator = other.numerator * (commonDenominator / other.denominator);
            return thisNumerator > otherNumerator ? *this : other;
        }
    }

    Fraction(int num, int denom) : numerator{ num }, denominator{ denom } {
        std::cout << "Creating Fraction object with address: " << this << std::endl;
    }

    void print() const {
        std::cout << numerator << "/" << denominator << " address: " << this << std::endl;
    }
};

int main()
{
    Fraction f1(2, 3);
    Fraction f2(1, 3);

    const Fraction& tmp = f1.getBigger(f2);
    tmp.print();

    return 0;
}
