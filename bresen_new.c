#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#define ROUND(x) ((int)(x+0.5))

 int x1,y1,x2,y2;


void disp()
{
   int m_new = 2 * (y2 - y1);
   int slope_error_new = m_new - (x2 - x1);
   glClear (GL_COLOR_BUFFER_BIT);
  
   glPointSize(2.5);
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_POINTS);
   for (int x = x1, y = y1; x <= x2; x++)
   {
      printf("\n\n(%d , %d )",x,y);
      glVertex2s(x,y);
 
      // Add slope to increment angle formed
      slope_error_new += m_new;
 
      // Slope error reached limit, time to
      // increment y and update slope error.
      if (slope_error_new >= 0)
      {
         y++;
         slope_error_new  -= 2 * (x2 - x1);
      }
   }
   glEnd();
   glFlush();
}


int main(int argc,char**argv)
{


printf("enter the points (x1,y1)  (x2,y2)\n");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);

glutCreateWindow("Bresenham");
gluOrtho2D(-100.0,100.0,-100.0,100.0);
glClearColor(1.0,1.0,1.0,0.5);
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}

