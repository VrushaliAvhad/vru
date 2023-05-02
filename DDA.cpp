#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

float X1,X2,Y1,Y2;

void Display()
{
	float dy,dx,length,x,y,k,Xin,Yin;
	dx=X2-X1;
	dy=Y2-Y1;
	
	if(abs(dx)>abs(dy))
	{
		length=abs(dx);
	}
	else
	{
		length=abs(dy);
	}
	
	Xin=dx/length;
	Yin=dy/length;
	
	x=X1;
	y=Y1;
	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	
	for(k=1 ; k<=length ; k++)
	{
		x=x+Xin;
		y=y+Yin;
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}	
	
	glFlush();
}

void init(void)
{
	glClearColor(1.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc,char** argv)
{
	cout<<"Enter Value of X1=";
	cin>>X1;
	
	cout<<"Enter Value of X2=";
	cin>>X2;
	
	cout<<"Enter Value of Y1=";
	cin>>Y1;
	
	cout<<"Enter Value of Y2=";
	cin>>Y2;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("DDA Line Drawing Algorithm");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	
	return 0;
	
	
}
