#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int i,j=0,n,count=0;
int rx1,rx2,ry1,ry2;
float x1[8],ya[8],a[8],b[8];
void init(void)
{

    glClearColor(1.0,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(300,-300,300,-300);

}
void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(rx1,ry1);
   glVertex2i(rx1,ry2);
   glVertex2i(rx2,ry2);
   glVertex2i(rx2,ry1);
   glEnd();
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
for(i=0;i<n;i++)
{
 glVertex2i(x1[i],ya[i]);
 glVertex2i(x1[i+1],ya[i+1]);
}glEnd();
if(j>n)
{   glBegin(GL_LINES);
 for(i=n;i<j;i++)
{
  glVertex2i(x1[i],ya[i]);
 glVertex2i(x1[i+1],ya[i+1]);}
   glEnd();


}   glFlush();
}
void clip(float e,float f,float m,int i)
{   

while(e<rx1||e>rx2||f<ry1||f>ry2)
{
if(e<rx1)
{
f+=m*(rx1-e);
e=rx1;
}
else if(e>rx2)
{
f+=m*(rx2-e);
e=rx2;
}
if(f<ry1)
{
e+=(ry1-f)/m;
f=ry1;
}
else if(f>ry2)
{
e+=(ry2-f)/m;
f=ry2;
}
}
x1[j]=e;
ya[j]=f;

printf("\nXX %f %f",x1[j],ya[j]);

j++;

}
void clipper()
{ int i;
float m;
for(i=0;i<n;i++)
{
m=(b[i+1]-b[i])/(a[i+1]-a[i]);
printf("\ni a[i] b[i]%d %f %f %f %f",i,a[i],b[i], a[i+1],b[i+1]);
clip(a[i],b[i],m,i);
clip(a[i+1],b[i+1],m,i);
}
x1[j]=x1[0];ya[j]=ya[0];
display();
glFlush();
}

void mouse(int btn,int state,int x,int y)  
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
       {  
           i=count;
            a[i]=(float)(300-x); 
            b[i]=(float)(y-300); 
            x1[i]=a[i];
            ya[i]=b[i];
            count++;
        if(count==n){a[count]=a[0];b[count]=b[0];
x1[count]=a[count];ya[count]=b[count];
display();glFlush();}
          
     }  
  if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)  
{
 clipper();glFlush();
}
  
}  

int main(int argc,char** argv)
{

int i;
float x[8],y[8],m;


printf("coordinates for rectangle : ");
scanf("%d%d%d%d",&rx1,&ry1,&rx2,&ry2);
printf("no. of sides for polygon : ");
scanf("%d",&n);
 glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("POLYGON CLIPPING");
    glutDisplayFunc(display);
glutMouseFunc(mouse);    
init();
    glutMainLoop();
    return 0;
}


