/*
 * Door.h
 *
 *  Created on: May 1, 2012
 *      Author: amro
 */

#ifndef DOOR_H_
#define DOOR_H_
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
class Door {
public:
	bool hor;
	bool upRight;
	int x1,x2,y1,y2;
	int r,g,b;
	int cet;
	bool closed;
	int lenth;
	Door(int ,int,int,int ,int,bool,bool,int ,int,int);
	void Display2()
	{
		glClear ( GL_COLOR_BUFFER_BIT ) ;
		glMatrixMode ( GL_MODELVIEW ) ;
		glLoadIdentity ( ) ;
		glPointSize ( 4.0 ) ;
		glPushMatrix ( ) ;
		glColor3f(0,1,0);

		glRotatef(90,0,0,1);
		glTranslatef(500,500,0);
		glBegin(GL_POLYGON);
			glVertex2i(x1,y1);
			glVertex2i(x2,y2);
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glVertex2i(x1-lenth*sin(cet*3.14/180),y1-lenth*cos(cet*3.14/180));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2i(x1,y1);
			glVertex2i(x2,y2);
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glVertex2i(x1-lenth*sin(cet*3.14/180),y1-lenth*cos(cet*3.14/180));
			glVertex2i(x1,y1);
		glEnd();
		if(cet<=90)
		{
		glBegin(GL_POLYGON);
			glColor3f(1,0,0);
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glVertex2i(x1-lenth*sin(cet*3.14/180),y1-lenth*cos(cet*3.14/180));
			glVertex2i((x1-lenth*sin(cet*3.14/180)-lenth/15*sin((90-cet)*3.14/180)),(y1-lenth*cos(cet*3.14/180))+lenth/15*cos((90-cet)*3.14/180));
			glVertex2i((x2-lenth*sin(cet*3.14/180)-lenth/15*sin((90-cet)*3.14/180)),(y2+lenth*cos(cet*3.14/180))-lenth/15*cos((90-cet)*3.14/180));

		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glVertex2i(x1-lenth*sin(cet*3.14/180),y1-lenth*cos(cet*3.14/180));
			glVertex2i((x1-lenth*sin(cet*3.14/180)-lenth/15*sin((90-cet)*3.14/180)),(y1-lenth*cos(cet*3.14/180))+lenth/15*cos((90-cet)*3.14/180));
			glVertex2i((x2-lenth*sin(cet*3.14/180)-lenth/15*sin((90-cet)*3.14/180)),(y2+lenth*cos(cet*3.14/180))-lenth/15*cos((90-cet)*3.14/180));
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glEnd();
		glPopMatrix();
		}
		else
		if(cet<=90)
		{
		glBegin(GL_POLYGON);
			glColor3f(1,0,0);
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glVertex2i(x1-lenth*sin(cet*3.14/180),y1-lenth*cos(cet*3.14/180));
			glVertex2i((x1-lenth*sin(cet*3.14/180)+lenth/15*sin((90-cet)*3.14/180)),(y1-lenth*cos(cet*3.14/180))+lenth/15*cos((90-cet)*3.14/180));
			glVertex2i((x2-lenth*sin(cet*3.14/180)+lenth/15*sin((90-cet)*3.14/180)),(y2+lenth*cos(cet*3.14/180))-lenth/15*cos((90-cet)*3.14/180));

		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glVertex2i(x1-lenth*sin(cet*3.14/180),y1-lenth*cos(cet*3.14/180));
			glVertex2i((x1-lenth*sin(cet*3.14/180)+lenth/15*sin((90-cet)*3.14/180)),(y1-lenth*cos(cet*3.14/180))+lenth/15*cos((90-cet)*3.14/180));
			glVertex2i((x2-lenth*sin(cet*3.14/180)+lenth/15*sin((90-cet)*3.14/180)),(y2+lenth*cos(cet*3.14/180))-lenth/15*cos((90-cet)*3.14/180));
			glVertex2i(x2-lenth*sin(cet*3.14/180),y2+lenth*cos(cet*3.14/180));
			glEnd();
		glPopMatrix();
		}

	}
	void Display()
	{
		if(cet%90!=0)
		{
			if(closed)
			{
				if(hor)
				{
					if(upRight)
						cet++;
					else
						cet--;
				}
			}
		}

	}
	virtual ~Door();
};

#endif /* DOOR_H_ */
