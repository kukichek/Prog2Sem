#pragma once
#include<iostream>
#include<string>

using namespace std;

class Fraction {
	int numenator, denominator;
	int gcd(int a, int b);
	void reduce(int n);
public:
	Fraction(int _num = 0, int _den = 1);
	friend ostream& operator<< (ostream &out, Fraction &obj);
	friend istream& operator>> (istream &in, Fraction &obj);
};