#include <iostream>
#include <cmath>

class Fraction {
public:
    Fraction();
    Fraction(int n, int d);

    int numerator() const;
    int denominator() const;

    Fraction sum(const Fraction& right);
    Fraction sub(const Fraction& right);
    Fraction mul(const Fraction& right);
    Fraction div(const Fraction& right);

    void write() const;

private:
    int n;
    int d;

    static int gcd(int a, int b);
    void normalise();
};


Fraction::Fraction() : n(0), d(1) {}


Fraction::Fraction(int num, int denom) : n(num), d(denom) {
    normalise();
}


int Fraction::numerator() const { return n; }
int Fraction::denominator() const { return d; }


int Fraction::gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}


void Fraction::normalise() {
    int g = gcd(n, d);
    n /= g;
    d /= g;
    if (d < 0) {
        n = -n;
        d = -d;
    }
}


Fraction Fraction::sum(const Fraction& right) {
    return Fraction(n * right.d + right.n * d, d * right.d);
}

Fraction Fraction::sub(const Fraction& right) {
    return Fraction(n * right.d - right.n * d, d * right.d);
}

Fraction Fraction::mul(const Fraction& right) {
    return Fraction(n * right.n, d * right.d);
}

Fraction Fraction::div(const Fraction& right) {
    return Fraction(n * right.d, d * right.n);
}


void Fraction::write() const {
    std::cout << n << '/' << d;
}
