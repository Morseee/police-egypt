/*
 * Car.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: morsee
 */

#include "Car.h"
#include "Image.h"
Car::Car(int height , int width ,bool upRight , bool hor ,Image *img) {

	if(hor && !upRight)
	{		nwest.y=306;
			nwest.x=300;
	}
	if(hor && upRight)
		{		nwest.y=306;
				nwest.x=300;
		}
	this->height=height;
	this->width=width;
	this->upRight=upRight;
	this->hor=hor;
	this->img=img;
	neast.x=nwest.x+height;
	neast.y=nwest.y;
	seast.x=nwest.x +height;
	seast.y=nwest.y-width;
	swest.x=nwest.x;
	swest.y=nwest.y-width;

	// TODO Auto-generated constructor stub
}
Car& Car::operator++()
		{
				if(mov)
				{

					if(hor)
					{
						if(upRight)
							swest.x++;
						else
							swest.x--;
					}
					else
					{
						if(upRight)
							swest.y++;
						else
							swest.y--;
					}

				}


    return *this;
}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

