#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include "test2.h"
typedef GLint vertex3[3];

vertex3 pts [8]={ {0,0,0},{0,1,0},{1,0,0},{1,1,0},{0,0,1},{0,1,1},{1,0,1},{1,1,1} };

int v=0,h=0,ceta=0;
float width=1,height=1;
int v1=v,h1=h;


float u=1.0;
float zzzz=0;
int beta=0;
void quad(GLint n1,GLint n2,GLint n3,GLint n4)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(1.0,0,0);
		glVertex3iv(pts[n1]);
		glVertex3iv(pts[n2]);
		glVertex3iv(pts[n3]);
		glVertex3iv(pts[n4]);
	glEnd();
	glPopMatrix();
}
void cube()
{
	glPushMatrix ( ) ;
	glBegin ( GL_QUADS );

	glColor3f ( 0 , 0 , 0 ) ;  glVertex3f ( -1 , -1, -1) ;
	glColor3f ( 0 , 0 , 1 ) ;	glVertex3f ( -1 , -1, 1 ) ;
	glColor3f ( 0 , 1 , 1 ) ;	glVertex3f ( -1 , 1 , 1 ) ;
	glColor3f ( 0 , 1 , 0 ) ;	glVertex3f ( -1 , 1 , -1) ;


	glColor3f ( 1 , 0 , 0 ) ;  glVertex3f ( 1 , -1, -1) ;
	glColor3f ( 1 , 0 , 1 ) ;	glVertex3f ( 1 , -1, 1 ) ;
	glColor3f ( 1 , 1 , 1 ) ;	glVertex3f ( 1 , 1 , 1 ) ;
	glColor3f ( 1 , 1 , 0 ) ;	glVertex3f ( 1 , 1 , -1) ;


	glColor3f ( 0 , 0 , 0 ) ;  glVertex3f ( -1 , -1, -1) ;
	glColor3f ( 0 , 0 , 1 ) ;	glVertex3f ( -1 , -1, 1 ) ;
	glColor3f ( 1 , 0 , 1 ) ;	glVertex3f ( 1 , -1 , 1 ) ;
	glColor3f ( 1 , 0 , 0 ) ;	glVertex3f ( 1 , -1 , -1) ;


	glColor3f ( 0 , 1 , 0 ) ;  glVertex3f ( -1 , 1, -1) ;
	glColor3f ( 0 , 1 , 1 ) ;	glVertex3f ( -1 , 1, 1 ) ;
	glColor3f ( 1 , 1 , 1 ) ;	glVertex3f ( 1 , 1 , 1 ) ;
	glColor3f ( 1 , 1 , 0 ) ;	glVertex3f ( 1 , 1 , -1) ;


	glColor3f ( 0 , 0 , 0 ) ;  glVertex3f ( -1 , -1, -1) ;
	glColor3f ( 0 , 1 , 0 ) ;	glVertex3f ( -1 , 1, -1 ) ;
	glColor3f ( 1 , 1 , 0 ) ;	glVertex3f ( 1 , 1 , -1 ) ;
	glColor3f ( 1 , 0 , 0 ) ;	glVertex3f ( 1 , -1 , -1) ;


	glColor3f ( 0 , 0 , 1 ) ;  glVertex3f ( -1 , -1, 1) ;
	glColor3f ( 0 , 1 , 1 ) ;	glVertex3f ( -1 , 1, 1 ) ;
	glColor3f ( 1 , 1 , 1 ) ;	glVertex3f ( 1 , 1 , 1 ) ;
	glColor3f ( 1 , 0 , 1 ) ;	glVertex3f ( 1 , -1 , 1) ;
	glEnd();

}
void myDisplay()
{



    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-10);
    glRotatef(40,1,1,0);
    //glRotatef(10,0,1,0);


    cube();
    glutSwapBuffers( ) ;




    glFlush();

}
void keyboard (unsigned char ch ,int x,int y)
{
	if(ch=='w')
		v+=10;
	else if (ch=='s')
		v+=10;
	else if(ch=='d')
		h+=10;
	else if (ch =='a')
		h-=10;
	else if (ch=='s')
			v-=10;
	else if(ch=='i')
		width*=2;
	else if (ch =='o')
		width/=2;
	else if (ch=='j')
		height*=2;
	else if(ch=='k')
		height/=2;
	else if (ch =='r')
		ceta+=5;
	else if(ch=='e')
		ceta-=5;
	else if(ch=='q')
		exit(0);
	else if(ch=='m')
	{
		width*=1.02;
		height*=1.02;
	}

	myDisplay();
}
void myTimer ( int val )
{

	static bool xx=false;
	if(xx)
	ceta += 1 ;
	else
		ceta-=1;
if(ceta==-45|| ceta==45)
	xx=!xx;
beta=90-ceta  - 2*45;
glutPostRedisplay( ) ;
 glutTimerFunc( 10 , myTimer , 0 ) ; // r e s e t t he t imer t o 1000 once more
}



void reshape ( int width , int height )
{
	glMatrixMode ( GL_PROJECTION ) ;
	glLoadIdentity ( ) ;
	gluPerspective ( 20 , width/(float ) height,5,15 ) ;
	glViewport ( 0 , 0 , width , height ) ;
	glMatrixMode ( GL_MODELVIEW ) ;
	glutPostRedisplay ( ) ;
}

int main (int argc,char ** argv)
{

	test2 zz;
	zz.set_values(1,2);
	printf("%x %d",zz.x,zz.y);

    return 0;
}

