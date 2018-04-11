#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1,x2,x3,y1,y2,y3,nx1,nx2,nx3,ny1,ny2,ny3,xf,yf;


void draw()
{

	glutCreateWindow("Reflect&Shear");
	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(0.8f,0.0f,0.0f);
  	gluOrtho2D(-200,200,-200,200);
  	glBegin(GL_LINES);
  	glVertex2i(-200,0);
  	glVertex2i(200,0);
  	glEnd();
  	glColor3f(0.8f,0.0f,0.0f);
  	glBegin(GL_LINES);
  	glVertex2i(0,-200);
  	glVertex2i(0,200);
  	glEnd();
	glColor3f(1.0f,1.0f,0.0f);
  	glBegin(GL_TRIANGLES);
  	glVertex2f(x1,y1);
  	glVertex2f(x2,y2);
  	glVertex2f(x3,y3);
  	glEnd();
 	glColor3f(1.0f,0.0f,0.0f);
  	glBegin(GL_TRIANGLES);
 	glVertex2f(nx1,ny1);
  	glVertex2f(nx2,ny2);
  	glVertex2f(nx3,ny3);
  	glEnd();
  	glFlush();
}

void main(int argc,char **argv)
{
	int c;
	void choose(char);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	
	glutInitWindowSize(640,480);
  	glutInitWindowPosition(200,150);
	printf("Enter the points of the triangle\n\n");
	scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
	while(1)
	{
	printf("\n\n1.REFLECTION\n\n2.SHEAR\n\n3.EXIT");
	printf("\nEnter your choice : ");
	scanf("%d",&c);
		
	switch(c)
	{
		case 1: choose('r');break;
		case 2: choose('s');break;
		case 3:	exit(0);
	}
	
	}
	
	glutDisplayFunc(draw);
  	glutMainLoop();

}


void choose(char cc)
{
	int ch,sh;
	if(cc=='r')
	{
		printf("\n1.Reflection on x-axis\n2.Reflection on y-axis\n3.Reflection on x=y\n4.Reflection on origin");
		printf("\n\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:nx1=x1;ny1=-y1;
			       nx2=x2;ny2=-y2;
			       nx3=x3;ny3=-y3;
			       break;
			case 2:nx1=-x1;ny1=y1;
			       nx2=-x2;ny2=y2;
			       nx3=-x3;ny3=y3;
			       break;
			case 3:nx1=y1;ny1=x1;
			       nx2=y2;ny2=x2;
			       nx3=y3;ny3=x3;
			       break;
			case 4:nx1=-x1;ny1=-y1;
			       nx2=-x2;ny2=-y2;
			       nx3=-x3;ny3=-y3;
			       break;
		}
	}
	if(cc=='s')
	{
		printf("\n1.Shear of x-axis\n2.Shear of y-axis");
		printf("\n\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n\nEnter shear factor : ");
			       scanf("%d",&sh);
			       nx1=x1+sh*y1;ny1=y1;
			       nx2=x2+sh*y2;ny2=y2;
			       nx3=x3+sh*y3;ny3=y3;
			       break;
			case 2:nx1=x1;ny1=y1+sh*x1;
			       nx2=x2;ny2=y2+sh*x2;
			       nx3=x3;ny3=y3+sh*x3;
			       break;
			
		}
	}
  draw();
}

