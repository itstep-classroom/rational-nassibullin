#ifndef H_RATIONAL
#define H_RATIONAL

#include <iostream>
#include <algorithm>

using namespace std;	

struct Rational {
    int numerator;
    int denominator;
};

void read(Rational &x) {
    cin >> x.numerator;
    cin.ignore();
    cin >> x.denominator;
}

void print(Rational x) {
	if (x.numerator == x.denominator)
		cout << x.numerator << endl;
	else
    	cout << x.numerator << '/' << x.denominator << endl;
}

void simplify(Rational &x) {
    int d = 1;
    for (int i = 1; i <= min(x.numerator, x.denominator); i++)
        if (!(x.numerator % i) && !(x.denominator % i))
            d = i;
    x.numerator /= d;
    x.denominator /= d;
}

Rational rational(int n, int m) {
    Rational x;
    x.numerator = n;
    x.denominator = m;
    simplify(x);
    return x;
}

Rational add(Rational a, Rational b) {
    int numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    int denominator = a.denominator * b.denominator;
    return rational(numerator, denominator);
}

Rational add(int a, Rational b) {
    return add(rational(a, 1), b);
}

Rational add(Rational a, int b) {
    return add(a, rational(b, 1));
}

Rational sub(Rational a, Rational b) {
    int numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    int denominator = a.denominator * b.denominator;
    return rational(numerator, denominator);
}

Rational sub(int a, Rational b) {
	return sub(rational(a, 1), b);
}
Rational sub(Rational a, int b) {
	return sub(a, rational(b, 1));
}

Rational mult(Rational a, Rational b) {
    int numerator = a.numerator * b.numerator;
    int denominator = a.denominator * b.denominator;
    return rational(numerator, denominator);
}

Rational mul(int a, Rational b) {
	return mult(rational(a, 1), b);
}

Rational mul(Rational a, int b) {
	return mult(a, rational(b, 1));
}

Rational inv(Rational a) {
    return rational(a.denominator, a.numerator);
}

Rational div(Rational a, Rational b) {
	b = inv(b);
    return mult(a, b);
}

Rational div(int a, Rational b) {
	return div(rational(a, 1), b);
}
Rational div(Rational a, int b) {
	return div(a, rational(b, 1));
}

bool lt(Rational r1, Rational r2) {
	return r1.numerator*r2.denominator < r2.numerator*r1.denominator;
}
bool gt(Rational r1, Rational r2) {
	return r1.numerator*r2.denominator > r2.numerator*r1.denominator;
}
bool le(Rational r1, Rational r2) {
	return r1.numerator*r2.denominator <= r2.numerator*r1.denominator;
}
bool ge(Rational r1, Rational r2) {
	return r1.numerator*r2.denominator >= r2.numerator*r1.denominator;
}
bool eq(Rational r1, Rational r2) {
	return r1.numerator*r2.denominator == r2.numerator*r1.denominator;
}
bool ne(Rational r1, Rational r2) {
	return r1.numerator*r2.denominator != r2.numerator*r1.denominator;
}

void sortBI(Rational list[], int size) {
	sort(list, list + size, &lt);
}

void sortBD(Rational list[], int size) {
	sort(list, list + size, &gt);
}

#endif
