#pragma once
#include "stdafx.h"
#include "Van.h"

Van::Van() : Automobile() {
	seats_ = 0;
}

Van::Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int seats) : Automobile() {
	seats_ = seats;
}

bool Van::park(bool lot[], int size) {
	if (seats_ <= 7) {
		return Automobile::park(lot, size);
	}
	else {
		int spot = size;
		for (int i = 0; i < size - 1; i++) {
			if (lot[i] == false && lot[i + 1] == false)
				spot = i;
		}
		if (spot >= size)
			return false;
		else {
			lot[spot] = true;
			lot[spot + 1] = true;
			set_stall(spot);
			return true;
		}
	}
}