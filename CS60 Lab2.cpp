// CS60 Lab2.cpp : Defines the entry point for the console application.
//

//This program allows for the addition and multiplication of rational numbers
//This program is simply to become familiar with the idea of classes and operator overloading

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Rational {
public:
	//constructors
	Rational(const int nume , const int denom );
	Rational();
	void reduce();
	void operator +=(Rational rhs);
	
	//getters
	int get_nume() const;
	int get_denom() const;

private:
	int nume_;
	int denom_;
};

Rational::Rational(const int nume , const int denom) {
	nume_ = nume;
	denom_ = denom;
}

Rational::Rational() {
	nume_ = 0;
	denom_ = 1;
}

void Rational::reduce() {
	int max = nume_;
	for (int i = max; i > 0; i--) {
		if (denom_ % i == 0 && nume_ % i ==0) {
			denom_ = denom_ / i;
			nume_ = nume_ / i;
		}
	}
}

void Rational::operator +=(Rational rhs) {
	reduce();
	rhs.reduce();
	nume_ = ((nume_ * rhs.get_denom() + denom_ * rhs.get_nume()));
	denom_ = denom_ * rhs.get_denom();
	reduce();
}

int Rational::get_nume() const{
	return nume_;
}

int Rational::get_denom() const {
	return denom_;
}

Rational operator *(Rational& lhs, Rational& rhs) {
	Rational a(lhs.get_nume() * rhs.get_nume(), lhs.get_denom() * rhs.get_denom());
	rhs.reduce();
	lhs.reduce();
	return a;
}
Rational operator +(Rational& lhs, Rational& rhs) {
	Rational a((lhs.get_nume() * rhs.get_denom() + lhs.get_denom() * rhs.get_nume()), (lhs.get_denom() * rhs.get_denom()));
	lhs.reduce();
	rhs.reduce();
	return a;
}
bool operator ==(Rational& lhs, Rational& rhs) {
	lhs.reduce();
	rhs.reduce();
	if (lhs.get_nume() == rhs.get_nume() && lhs.get_denom() == rhs.get_denom()) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	Rational a(1, 2);
	cout << "a: "<< a.get_nume() << "/" << a.get_denom() << endl;
	Rational b(2, 4);
	cout << "b: "<< b.get_nume() << "/" << b.get_denom() << endl;
	Rational c(3, 4);
	cout << "c: " << c.get_nume() << "/" << c.get_denom() << endl;
	Rational d(5, 4);
	cout << "d: "<< d.get_nume() << "/" << d.get_denom() << endl;
	b += a;
	cout << "b+a = " << b.get_nume() << "/" << b.get_denom() << endl;
	c += d;
	cout << "c+d = " << c.get_nume() << "/" << c.get_denom() << endl;
	
	system("pause");

    return 0;
}

