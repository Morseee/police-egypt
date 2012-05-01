/*
 * Door.cpp
 *
 *  Created on: May 1, 2012
 *      Author: amro
 */

#include "Door.h"

Door::Door(int x1,int x2 , int y1, int y2,int lenth,bool hor,bool upRight,int r , int g , int b) {
this->x1=x1;
this->x2=x2;
this->y1=y1;
this->y2=y2;
this->hor=hor;
this->upRight=upRight;
this->r=r;
this->g=g;
this->b=b;
this->lenth=lenth;

}

Door::~Door() {
	// TODO Auto-generated destructor stub
}

