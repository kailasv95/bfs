#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<unistd.h>
int n,eg,count=0,f=0,f2=0,v1[2],v2[2];
int h=-1,k=-1,l=0;
int adj[15][10],op[10],node[10][3],ncount[10];
int dist[100],parent[100],q[40],visited[20],length=0,rear;
int weights[50][3],numedge=0;
void drawedge(int a,int b,int c,int d)
{
 glPointSize(4.0);
 glBegin(GL_LINES);
 glVertex2i(a,b);
 glVertex2i(c,d);
 glEnd();
 glFlush();
}
void print()
{
 for(int i=0;i<n;i++)
  {
   printf("%d",node[i][0]);
   }
 }
void drawnode(int x,int y)
{
  glBegin(GL_POLYGON);
  glVertex2i(x-10,y-10);
  glVertex2i(x-10,y+10);
  glVertex2i(x+10,y+10);
  glVertex2i(x+10,y-10);
  glEnd();
  glFlush();
}
void draw()
{
 glColor3f(1.0f,0.0f,0.0f);
 for(int i=0;i<n;i++)
  {
    sleep(1);
    drawnode(node[i][0],node[i][1]);
    drawedge(node[i][0],node[i][1],node[parent[i]][0],node[parent[i]][1]);

  }
}
int dj()
{
 while(rear!=0)
  {
   int min=1000;
   int minone=0;
   int mintwo=0;
   int wet=0;
   for(int i=0;i<length;i++)
    {
      for(int j=0;j<ncount[visited[i]];j++)
       {
        for(int edge=0;edge<numedge;edge++)  
         {
           if((weights[edge][0]==visited[i]&&weights[edge][1]==adj[visited[i]][j])||(weights[edge][0]==adj[visited[i]][j]&&weights[edge][1]==visited[i]))
             {
               wet=weights[edge][2];
               if(dist[visited[i]]+wet<dist[adj[visited[i]][j]])
                {
                      min=dist[visited[i]]+wet;
                      minone=visited[i];
                      mintwo=adj[visited[i]][j];
                      parent[mintwo]=minone;
                      dist[mintwo]=min;
                      int index=-1;
                       for(int i=0;i<rear;i++)
                        {
                         printf("%d",q[i]);
                         if(q[i]==mintwo)
                         {
                         index=i;
                         break;
                         }
                    }
                   if(index!=-1)
                    {
                      for(int i=index;i<rear-1;i++)
          
                         q[i]=q[i+1];
                         rear=rear-1;
                         visited[length]=mintwo;
                         length+=1;  
                        }
                     }
                   }
               }
            }
          }
     }
   for(int i=0;i<n;i++)
     {
       printf("distance: %d",i);
       printf(" ");
       printf("%d",dist[i]);
     }
  draw();
return 0;
} 
int check(int a,int b)
{
  int k=-1;
  for(int i=0;i<n;i++)
   {
     if((a<=node[i][0]+10&&a>=node[i][0]-10)&&(b<=node[i][1]+10&&b>=node[i][1]-10))
{
 printf("a");
 k=i;
}
else
 continue;
}
return k;
}
void init()
{
  dist[0]=0;
  parent[0]=0;
  for(int i=1;i<n;i++)
    {
      dist[i]=1000;
      q[i-1]=i;
       parent[i]=-1;
     }
  rear=n-1;
  visited[0]=0;
length=1;
}
void mouseClicks(int button,int state,int x,int y)
{
 if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
  {
    if(count<n)
     {
       f=0;
       node[count][0]=x;
       node[count][1]=y;
       glColor3f(0.0f,0.0f,1.0f);
       drawnode(x,y);
       glRasterPos2i(x-30,y);
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,65+count);
       count++;
      }
   else if(count==n&&f==0)
      {
       f=1;
      printf("\nNode complete");
      }
    if(f==1)
     {
       printf("\nDraw edges");
        if(f2==0)
         {
           h=check(x,y);
            if(h!=-1)
              {
                v1[0]=node[h][0];
                v1[1]=node[h][1];
                f2=1;
               }
            }
         else if(f2==1)
         {
           k=check(x,y);
           if(k!=-1)
            {
              if(h!=k)
               {
                v2[0]=node[k][0];
                v2[1]=node[k][1];
                f2=0;
                adj[h][ncount[h]]=k;
                ncount[h]++;
                adj[k][ncount[k]]=h;
                ncount[k]++;
                printf("\nEnter The Weights:");
                scanf("%d",&weights[numedge][2]);
                weights[numedge][0]=h;
                weights[numedge][1]=k;
                glRasterPos2i(((v1[0]+v2[0])/2),((v1[1]+v2[1])/2));
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+weights[numedge][2]);
                glColor3f(0.0f,0.0f,1.0f);
                drawedge(v1[0],v1[1],v2[0],v2[1]);
                numedge++;
                h=-1;
                k=-1;
                l++;
                printf("\n l:%d",l);
                if(l==eg)
                   {
                      printf("Edge done");
f=2;
}
}
}
}
}
else if(f==2)
{
init();
print();
dj();
}
}
}
int main(int argc,char** argv)
{
  for(int i;i<10;i++)
         {
          ncount[i]=0;
          node[i][2]=0;
        }
        printf("\nEnter no of node:");
        scanf("%d",&n);
        printf("\nEnter no of edges:");
        scanf("%d",&eg);
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(500,500);
			  glutCreateWindow("BFS");
glClearColor(1.0,1.0,1.0,0.0);
glPointSize(4.0);
gluOrtho2D(0,500,500,0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0f,0.0f,0.0f);
glutMouseFunc(mouseClicks);
glutMainLoop();
return 0;
}
