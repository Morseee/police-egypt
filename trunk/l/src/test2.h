/*
 * test2.h
 *
 *  Created on: Apr 27, 2012
 *      Author: amro
 */

#ifndef TEST2_H_
#define TEST2_H_

class test2 {
public:
	test2();
	int x, y;
	    void set_values (int x,int y)
	    {
	    this->x=x;
	    this->y=y;

	    }
	    int area () {return (x*y);}
	virtual ~test2();


};

#endif /* TEST2_H_ */
