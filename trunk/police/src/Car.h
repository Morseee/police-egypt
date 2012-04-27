/*
 * Car.h
 *
 *  Created on: Apr 27, 2012
 *      Author: morsee
 */

//#ifndef CAR_H_
#define CAR_H_
typedef int point[2];
class Car {

public:

	point nwest;    // north west of the car
	int lenth;
	int width;
	int direction;  // 0 right , 1 left , 2 up , 3 down
	bool mov;       // 0 = stop , 1= moving


	Car();


	virtual ~Car();

};


//#endif /* CAR_H_ */
