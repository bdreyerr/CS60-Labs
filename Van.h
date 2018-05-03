#pragma once
#ifndef VAN_H
#define VAN_H
#include "automobile.h"


class Van : public Automobile {
public:
	Van();
	Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int seats);
	bool park(bool lot[], int size);
private:
	int seats_;
};



#endif