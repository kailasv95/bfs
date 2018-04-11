#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
#define ROUND(x) ((int)(x+0.5))
int xa,xb,ya,yb;

void display(void)
{
	int dx=xb-xa,dy=yb-ya,steps,k,i;
	float xinc,yinc,x=xa,y=ya;
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glPointSize(2.5);
	
	if(abs(dx)>abs(dy))
	steps=abs(dx);
	else
	steps=abs(dy);

	xinc=dx/(float)steps;
	yinc=dy/(float)steps;
	glBegin(GL_POINTS);
	glVertex2s(ROUND(x),ROUND(y));
	for(k=0;k<steps;k++)
	{
	x+=xinc;
	y+=yinc;
	glVertex2s(ROUND(x),ROUND(y));
	printf("%1f  %1f\n",x,y);
	}
	glColor3f(0.0,0.0,0.0);
	for(i=-100;i<=100;i++)
        {
            glVertex2s(i,0);
            glVertex2s(0,i);
         }
      for(i=-2;i<=2;i++)
        {
            glVertex2s(95+i,4+i);
            glVertex2s(95-i,4+i);
      }
      for(i=0;i<=2;i++)
        {
            glVertex2s(4+i,95+i);
            glVertex2s(4-i,95+i);
             glVertex2s(4,95-i);
        }
        glEnd(); 
        glFlush();
}
 int main(int argc,char**argv)
{

printf("enter the points (x1,y1)  (x2,y2)\n");
scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);

glutCreateWindow("Custom Window @@$$@@");
glClearColor(1.0,0.95,0.98,1.0);
gluOrtho2D(-100.0,100.0,-100.0,100.0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}



