// CS60 Lab3.cpp : Defines the entry point for the console application.
//


//This program will be able to store an integer with up to 20 digits using an array of shorts
//You will be able to add these large numbers and compare them with others

#include "stdafx.h"
#include "biguint.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

biguint::biguint() { //Defualt constructor which sets each value of the array to 0
	for(int i = 0; i < CAPACITY; i++) {
		data_[i] = 0;
	}
}

biguint::biguint(const std::string &s) {//Constructor that puts a string input by the user into the array backwards
	int size = s.size();
	for (int i = 0; i < size; i++) {
		assert(s[i] >= '0' && s[i] <= '9'); //Throws error if any char in the string is not an int between 1 and 9
	}
	for (int i = 0; i < size; i++) {
		data_[i] = s[size - i - 1] - '0';
		//DEBUG: cout << "i: " << i << " data_[i]: " << data_[i] << endl; //Fills in the array backwards, putting the 10s place digit in the first spot of the array
	}
	for (int i = size; i < CAPACITY; i++) { //Fills the empty spots in the array with 0s
		data_[i] = 0;
	}
}

unsigned short biguint::operator [](std::size_t pos) const { //Overloaded operator [] that returns the index of pos for that objects data_
	assert(pos < CAPACITY);
	return(data_[pos]);
}

ostream& operator <<(ostream& out, biguint &a) { //Function to print an object of class biguint
	for (int i = 0; i < a.CAPACITY; i++) {
		if (a[a.CAPACITY - i - 1] != 0) {
			for (int j = i; j < a.CAPACITY; j++) {
				out << a[a.CAPACITY - j - 1];
			}
			break;
		}
	}
	return out;
}

void biguint::operator += (const biguint & b) { //+= function
	for (int i = 0; i < b.CAPACITY; i++) {
		data_[i] += b.data_[i];
		if (data_[i] > 10) {
			data_[i + 1]++;
			data_[i] -= 10;
		}
		
	} 
}
	//	post: returns 1 if this biguint > b
	//               0 if this biguint == b
	//              -1 if this biguint < b
int biguint::compare(const biguint & b) const { 
	for (int i = 1; i <= CAPACITY; i++) {
		if (data_[CAPACITY-i] > b.data_[CAPACITY-i])
			return 1;
		else if (data_[CAPACITY-i] < b.data_[CAPACITY-i])
			return -1;
	}
	return 0;
	
}

//Comparison Operators
bool operator < (const biguint &a, const biguint &b) {
	return(a.compare(b) == -1);
}
bool operator <= (const biguint &a, const biguint &b) {
	return(a.compare(b) != 1);
}
bool operator != (const biguint &a, const biguint &b) {
	return(a.compare(b) != 0);
}
bool operator == (const biguint &a, const biguint &b) {
	return(a.compare(b) == 0);
}
bool operator >= (const biguint &a, const biguint &b) {
	return(a.compare(b) != -1);
}
bool operator > (const biguint &a, const biguint &b){
	return(a.compare(b) == 1);
}


int main()
{
	cout << "Input your number, do not use any non numerical characters" << endl;
	string input, input2;
	cin >> input;
	biguint a(input);
	cout << "Input another number, do not use any non numerical characters" << endl;
	cin >> input2;
	biguint b(input2);

	cout << "a: " << a << endl << "b: " << b << endl;
	cout << "a < b: " << (a < b) << endl;
	cout << "a <= b: " << (a <= b) << endl;
	cout << " a != b " << (a != b) << endl;
	cout << "a == b: " << (a == b) << endl;
	cout << "a >= b: " << (a >= b) << endl;
	cout << "a > b: " << (a > b) << endl;

	a += b;
	cout << "a + b = " << a << endl;

	system("pause");
    return 0;
}

