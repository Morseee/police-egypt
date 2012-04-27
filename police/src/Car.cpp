/*
 * Car.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: morsee
 */

#include "Car.h"
#include "Image.h"
Car::Car(int lenth , int width ,bool upRight , bool hor ,Image *img) {

	if(hor && !upRight)
	{		nwest.y=306;
			nwest.x=70;
	}
	this->lenth=lenth;
	this->width=width;
	this->upRight=upRight;
	this->hor=hor;
	this->img=img;
	neast.x=nwest.x+lenth;
	neast.y=nwest.y;
	seast.x=nwest.x +lenth;
	seast.y=nwest.y-width;
	swest.x=nwest.x;
	swest.y=nwest.y-width;

	// TODO Auto-generated constructor stub
}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

