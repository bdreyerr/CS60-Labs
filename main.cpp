// CS60 Lab5.cpp : Defines the entry point for the console application.
//

//This program acts as a way to practice inheritance in c++
//This program uses the classes Van and Pickup, which are inherited from the class automobile
//bool lot represents a car lot with 5 parking spaces in it, the function park is used to park an automobile in one of the spots

#include "stdafx.h"
#include "automobile.h"
#include <iostream>
#include "Pickup.h"
#include "Van.h"


using namespace std;
const static int spots = 5;

int main()
{
	bool lot[spots] = { false, false, false, false, false };
	cout << "1: spot is taken, 0: spot is free" << endl;


	Automobile a("Ferrari", "458 Italia", 2012, 245000, 1);
	a.park(lot, spots);
	
	Pickup b;
	b.park(lot, spots);
	
	Van c("Volkswagon", "Van", 2010, 20000, 4, 8);
	c.park(lot, spots);



	for (int i = 0; i < spots; i++) {
		cout <<"Spot "<< i << ": "<<lot[i] << endl;
	}

	system("pause");
    return 0;
}

