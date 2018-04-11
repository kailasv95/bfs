#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void setPixel(GLint x,GLint y)
{
glPointSize(3.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}
void Circle()
{
int xc,yc,r,x,y,p;
printf("\nEnter the centre position of the circle:");
scanf("%d%d",&xc,&yc);
printf("\nEnter the radius of the circle:");
scanf("%d",&r);
x=0;
y=r;
p=(5/4)-r;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);
//drawing x axis and y axis
glBegin(GL_LINES);
glVertex2i(0,-200);
glVertex2i(0,200);
glEnd();
while(x<=y)
{
setPixel(xc+x,yc+y);
setPixel(xc+y,yc+x);
setPixel(xc-x,yc+y);
setPixel(xc+y,yc-x);
setPixel(xc-x,yc-y);
setPixel(xc-y,yc-x);
setPixel(xc+x,yc-y);
setPixel(xc-y,yc+x);
if(p<0)
p=p+(2*x)+3;
else
{
p=p+2*x+2+1-(2*y-2);
y-=1;
}
x++;
}
printf("\nCircle drawn successfully\n");
glEnd();
glFlush();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,150);
glutCreateWindow("Midpoint circle");
glClearColor(1.0,0.95,0.98,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-200,200,-200,200);
glutDisplayFunc(Circle);
glutMainLoop();
return 0;
}
 

 

