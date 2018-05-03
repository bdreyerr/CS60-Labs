#pragma once
#ifndef PICKUP_H
#define PICKUP_H
#include "automobile.h"

class Pickup : public Automobile {
public:
	Pickup();
	Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int haul, bool cab);
	bool park(bool lot[], int size);

private:
	int haul_;
	bool cab_;
};

#endif