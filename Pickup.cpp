#include "stdafx.h"
#include "Pickup.h"
#include "automobile.h"

Pickup::Pickup() : Automobile() {
	haul_ = 0;
	cab_ = false;
}

Pickup::Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int haul, bool cab) : Automobile() {
	haul_ = haul;
	cab_ = cab;
}


bool Pickup::park(bool lot[], int size){
    int spot=size;
    for(int i=0; i<size-1; i++){
        if(lot[i] == false && lot[i+1] == false)
            spot = i;
    }
    if(spot>=size)
       return false;
    else{
        lot[spot] = true;
		lot[spot + 1] = true;
        set_stall(spot);
        return true;
    }
	
	 
}