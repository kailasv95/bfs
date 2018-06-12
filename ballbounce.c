#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
float posx,posy,movespeedx,movespeedy;
bool init()
{
glClearColor(0.93f,0.93f,0.93f,0.0f);
glColor3f(0.0f,0.0f,0.0f);
return true;
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
float PI=3.14159265;
float radius=0.03f;
if(posx+radius>1.0f||posx-radius<-1.0f)
{
movespeedx*=-1;
}
if(posy+radius>1.0f||posy-radius<-1.0f)
{
movespeedy*=-1;
}
posx+=movespeedx;
posy+=movespeedy;
glBegin(GL_POLYGON);
for(float angle=0;angle<360;angle+=5)
{
float xc=sin(angle*PI/180);
float yc=cos(angle*PI/180);
glVertex3f(xc+posx,yc+posy,0.0f);
}
glEnd();
glFlush();
glutSwapBuffers();
glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
if(key==27)
exit(1);
}

int main(int argc,char *argv[])
{
srand(time(NULL));
int step=10;
posx=(rand()%step)-0.5f;
posy=(rand()%step)/step-0.05f;
movespeedx=0.02f;
movespeedy=0.03f;
glutInit(&argc,argv);
glutInitWindowPosition(50,50);
glutInitWindowSize(500,500);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
glutCreateWindow("05-Primitives");
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
if(!init())
return 1;
glutMainLoop();
return 0;
}





























