/*
 * Car.h
 *
 *  Created on: Apr 27, 2012
 *      Author: morsee
 */

#ifndef CAR_H_
#define CAR_H_
#include"Image.h"
struct point{
	int x,y;
};

class Car {

public:


	point nwest;    // north west of the car
	point neast;
	point swest;
	point seast;
	int height;
	int width;
	bool upRight; // 1 up or right , 0 down  or left
	bool hor;// 1 right left , 0 down up
	bool mov;       // 0 = stop , 1= moving
	Image *img;

	Car(int, int, bool, bool, Image*);
	void Display()
	{
		glPushMatrix ( ) ;
			img->display ( swest.x , swest.y ) ;
		glPopMatrix ( ) ;
	}
	Car& operator++();

	virtual ~Car();

};


#endif /* CAR_H_ */
