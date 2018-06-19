#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<ctime>
using namespace std;
float minX=0,minY=250,hourX=0,hourY=180,posX=0,posY=300;
float X=0,Y=280;
void drawcircle(int xc,int yc,int r)
{
  float p0;
  int xa[1000],ya[1000],n=0,i;
  int x,y;
  p0=5/4-r;
  x=0;
  y=r;
  glPointSize(3.0);
  glBegin(GL_POINTS);
  glVertex2i(xc,yc);
  glColor3f(0.0,0.0,0.0);
  x=x;
  y=y;
  glVertex2i(x+xc,y+yc);
  i=0;
  xa[i]=x;
  ya[i]=y;
  n++;i++;
    while(x<y)
    {
      if(p0<0)
      {
        x=x+1;
        p0=p0+(2*x+1);
        glVertex2i(x+xc,y+yc);
        xa[i]=x;
        ya[i]=y;
        n++;i++;
      }
      else
      {
        x=x+1;
        y=y-1;
        p0=p0+(2*x+1)-(2*y+1);
        glVertex2i(x+xc,y+yc);
        xa[i]=x;
        ya[i]=y;
        n++;i++;
      }
    }
  i=0;
  while(i<n)
  {
    glVertex2i(-xa[i]+xc,-ya[i]+yc);
    glVertex2i(ya[i]+xc,xa[i]+yc);
    glVertex2i(-ya[i]+xc,-xa[i]+yc);
    glVertex2i(-xa[i]+xc,ya[i]+yc);
    glVertex2i(xa[i]+xc,-ya[i]+yc);
    glVertex2i(-ya[i]+xc,xa[i]+yc);
    glVertex2i(ya[i]+xc,-xa[i]+yc);
    i++;
  }
}
void display()
{
  int xr=0,yr=0;
  glPointSize(3.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  glColor3f(0.0f,0.0f,0.0f);
  glVertex2i(0.0,0.0);
  glVertex2i(X,Y);
  glVertex2i(0.0,0.0);
  glVertex2i(minX,minY);
  glVertex2i(0.0,0.0);
  glVertex2i(hourX,hourY);
  glEnd();
  drawcircle(0,0,300);
  glEnd();
  glPointSize(6.0);
  glBegin(GL_LINES);
  int i=0;
  while(i<12)
  {
    float angle=(3.14/180)*i*30;
    posX=-250*sinf(-angle);
    posY=250*cosf(-angle);
    glVertex2i(posX,posY);
    posX=-285*sinf(-angle);
    posY=285*cosf(-angle);
    glVertex2i(posX,posY);
    i++;
  }
  glEnd();
  glFlush();
  time_t now=time(0);
  tm*ltm=localtime(&now);
  float angle=(3.14/180)*ltm->tm_sec*6;
  X=-280*sinf(-angle);
  Y=280*cosf(-angle);
  angle=(3.14/180)*ltm->tm_min*6;
  minX=-250*sinf(-angle);
  minY=250*cosf(-angle);
  angle=(3.14/180)*(ltm->tm_hour*30+(ltm->tm_min*0.5));
  hourX=-180*sinf(-angle);
  hourY=180*cosf(-angle);
  glutPostRedisplay();
}
int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(640,640);
  glutInitWindowPosition(500,150);
  glutCreateWindow("My First Attempt");
  glClearColor(1.0,1.0,1.0,1.0);
  glPointSize(6.0);
  gluOrtho2D(-600,600,-600,600);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
