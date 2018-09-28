/*
Rational newRational(int n, int m); // инициализирует
void print(Rational r, char del='\n') // печатает
void read(Rational &r); // читает

void simplify(Rational& r); // упрощает дробь
int gcd(int n, int m); // для упрощения дополнительная функция, НОД

// арифметические операции
r3 = add(r1,r2), add(r,int), add(int,r)
r3 = sub(r1,r2), sub(r,int), sub(int,r)
r3 = mul(r1,r2), mul(r,int), mul(int,r)
r3 = div(r1,r2), div(r,int), div(int,r)

r2 = inv(r1) // inverse, например inv(3/4) = 4/3

// операции сравнения
bool lt(r1,r2) // < less than
bool gt(r1,r2) // > greater than
bool le(r1,r2) // <= less or equal to
bool ge(r1,r2) // >= greate or equal to
bool eq(r1,r2) // == equal to
bool ne(r1,r2) // != not equal to

*/

#include <iostream>
using namespace std;

struct Rational {
	int n; // числитель numerator
	int m; // знаменатель denominator
};

int gcd(int n, int m) { // greatest common divisor, НОД
	if (n == 0) return 1;

	n = (n < 0 ? -n : n);
	m = (m < 0 ? -m : m);
	int mi = (n < m ? n : m);

	int g;
	for (g = mi; g > 1; g--)
		if (n%g == 0 && m%g == 0) break;

	return g;
}

void simplify(Rational & r) { // 16/24 = 2/3
	int g = gcd(r.n, r.m);
	r.n /= g;
	r.m /= g;
}

Rational newRational(int n, int m) {
	Rational r;
	r.n = n;
	r.m = m;
	simplify(r);
	return r;
}

void print(Rational r, char del='\n') {
	cout << r.n << "/" << r.m << del;
}


Rational add(Rational r1, Rational r2) {
	Rational r3;
	r3.m = r1.m*r2.m;
	r3.n = r1.n*r2.m + r2.n*r1.m;
	return r3;
}
Rational add(Rational r, int n) {
	return add(r, newRational(n, 1));
}
Rational add(int n, Rational r) {
	return add(newRational(n, 1),r);
}

void read(Rational &r) {
	cin >> r.n;
	cin.ignore();
	cin >> r.m;
}

bool lt(Rational r1, Rational r2) { // less than
	return r1.n*r2.m < r2.n*r1.m;
}



int main() {
	
	Rational sum = newRational(0, 1); // 0/1

	int n;
	cin >> n;
	Rational r[100];
	for (int i = 0; i < n; i++) {
		read(r[i]);
		sum = add(sum, r[i]);
	}
	simplify(sum);


	for (int i = 0; i < n-1; i++) {
		print(r[i],' ');
	}
	print(r[n - 1]);

	cout << "sum = ";
	print(sum);
	

}

/*
5
1/2 3/2 1/4 5/2 7/9

*/
