
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>


void display();

float xmin=-100;
float ymin=-100;
float xmax=100;
int first=0;
float ymax=100;
float xd1,yd1,xd2,yd2;


void init(void)
{

    glClearColor(1.0,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(300,-300,300,-300);

}

int code(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void cohen_Line(float x1,float y1,float x2,float y2)
{ printf("\n%f %f %f %f",x1,y1,x2,y2);
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
           exit(0);
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else
       if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else
       if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           xd1=x;
           yd1=y;
           c1=code(xd1,yd1);
       }

       if(c==c2)
       {
           xd2=x;
           yd2=y;
           c2=code(xd2,yd2);
       }
}
printf("\nclip:%f %f %f %f",xd1,yd1,xd2,yd2);
 display();

}

void mouse(int btn,int state,int x,int y)  
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {  
            switch(first)  
            {  
            case 0:  
                 xd1=(float)(300-x);  
                 yd1=(float)(y-300);  
                 printf("\nP1-%d %d\n",x,y);
                 first=1;  
                 break;  
            case 1:  
                 xd2=(float)(300-x);  
                 yd2=(float)(y-300);  
                 printf("\nP2-%d %d \n",x,y);  
                 first=0;
display();
glFlush();
       
                 break;  
            }  
     }  
     else if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)  
     {
     cohen_Line(xd1,yd1,xd2,yd2);   
glFlush();
  }  
}


void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.9,1.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();
   glColor3f(0.3,1.0,0.0);
   glBegin(GL_LINES);
   glVertex2i(xd1,yd1);
   glVertex2i(xd2,yd2);
   glEnd();
   glFlush();


}


int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);

 glutMouseFunc(mouse);    
init();
    glutMainLoop();
    return 0;
}













