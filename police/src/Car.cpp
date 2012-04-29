/*
 * Car.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: morsee
 */

#include "Car.h"
#include "Image.h"
int posx[2]={300,380},posy[2]={560,640};
Car::Car(int height , int width ,bool upRight , bool hor ,Image *img) {

	if(hor && !upRight)
	{	swest.y=posx[1]- height;
		swest.x=1200;
	}
	if(hor && upRight)
	{
		swest.y=posx[0];
		swest.x=0;

	}
	if(!hor && upRight)
	{
		swest.x=posy[1]-width;
		swest.y=0;
	}
	if(!hor && !upRight)
	{
		swest.x=posy[0];
		swest.y=700;
	}
	this->height=height;
	this->width=width;
	this->upRight=upRight;
	this->hor=hor;
	this->img=img;

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

