#include <bits/stdc++.h>
#include <GL/glut.h>
#include <unistd.h>
using namespace std;
int nv,ne;
int i=0;
list<int> *adj;
struct line
{
  int s,d;
};
int addedge(int s,int d)
{
  adj[s].push_back(d);
  return 0;
}
struct point
{
  int x;
  int y;
};
struct line* edges;
struct point* vertices;
int bfs(int s);
int pointC(int x,int y)
{
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}
int point(int x,int y)
{
  vertices[i].x=x;
  vertices[i++].y=y;
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glRasterPos2f(x+10,y+10);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,i+47);
  glFlush();
}
void display()
{
}
void render(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    {
      if(i<nv)
      {
        point(x,y);
      }
    }
    else if(button==GLUT_RIGHT_BUTTON)
    {
      for(int i=0;i<ne;i++)
      {
        glBegin(GL_LINES);
         glVertex2i(vertices[edges[i].s].x,vertices[edges[i].s].y);
         glVertex2i(vertices[edges[i].d].x,vertices[edges[i].d].y);
        glEnd();
        glFlush();
      }
    }
    else if(button==GLUT_MIDDLE_BUTTON)
    {
      int s;
      cout<<"Enter the source vertex"<<endl;
      cin>>s;
      bfs(s);
    }
   glutDisplayFunc(display);
 }
int main(int argc, char** argv)
{
  int s,d;
  cout<<"Enter the no.of vertices\n";
  cin>>nv;
  adj=new list<int>[nv];
  vertices=new struct point[nv];
  cout<<"Enter the no.of edges\n";
  cin>>ne;
  edges=new struct line[ne];
  for(int i=0;i<ne;i++)
  {
    cin>>s>>d;
    addedge(s,d);
    edges[i].s=s;
    edges[i].d=d;
  }
  glutInit(&argc,argv);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("DDA Algorithm");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0,500,500,0);
  glutMouseFunc(render);
  glutMainLoop();
  return 0;
}
int bfs(int s)
{
  bool visited[nv];
  memset(visited,false,nv);
  list<int> queue;
  queue.push_back(s);
  glColor3f(1.0,0.0,0.0);
  visited[s]=true;
  list<int>::iterator i;
  while(!queue.empty())
  {
    s=queue.front();
    cout<<s<<" ";
    pointC(vertices[s].x,vertices[s].y);
    queue.pop_front();
    for(i=adj[s].begin();i!=adj[s].end();++i)
    {
      if(!visited[*i])
      {
        visited[*i]=true;
        queue.push_back(*i);
      }
    }
  }
}
