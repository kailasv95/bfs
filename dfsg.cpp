#include <bits/stdc++.h>
#include <GL/glut.h>
#include <unistd.h>
using namespace std;
int ne,nv;
int j=0;
list<int> *adj;
struct point
{
  int x,y;
};
struct line
{
  int s,d;
};
int pointC(int x,int y);
struct line* edges;
struct point* vertices;
int addedge(int s,int d);
void render(int button,int state,int x,int y);
int point(int x,int y);
int drawedge();
int dfs(int s);
int dfsUtil(int s,bool visited[]);
int main(int argc,char** argv)
{
  cout<<"Enter the no.of vertices\n";
  cin>>nv;
  adj=new list<int>[nv];
  vertices=new struct point[nv];
  cout<<"Enter the no.of edges\n";
  cin>>ne;
  edges=new struct line[ne];
  cout<<"Enter the edges\n";
  for(int i=0;i<ne;i++)
  {
    cin>>edges[i].s>>edges[i].d;
    addedge(edges[i].s,edges[i].d);
  }
  glutInit(&argc,argv);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("DFS");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0.0,500.0,500.0,0);
  glutMouseFunc(render);
  glutMainLoop();
  return 0;
}
int addedge(int s,int d)
{
  adj[s].push_back(d);
  return 0;
}
void render(int button,int state,int x,int y)
{
  if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
  {
    if(j<nv)
    {
      point(x,y);
    }
  }
  else if(button==GLUT_RIGHT_BUTTON)
  {
    drawedge();
  }
  else if(button==GLUT_MIDDLE_BUTTON)
  {
    int s;
    cout<<"Enter the source vertex"<<endl;
    cin>>s;
    dfs(s);
  }
}
int point(int x,int y)
{
  vertices[j].x=x;
  vertices[j++].y=y;
  glPointSize(5.0);
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POINTS);
    glVertex2i(x,y);
  glEnd();
  glRasterPos2f(x+10,y+10);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,j+47);
  glFlush();
  return 0;
}
int drawedge()
{
  glPointSize(2.0);
  glColor3f(1.0,1.0,1.0);
  for(int i=0;i<ne;i++)
  {
    glBegin(GL_LINES);
      glVertex2i(vertices[edges[i].s].x,vertices[edges[i].s].y);
      glVertex2i(vertices[edges[i].d].x,vertices[edges[i].d].y);
    glEnd();
  }
  glFlush();
}
int dfs(int s)
{
  bool visited[nv];
  memset(visited,false,nv);
  dfsUtil(s,visited);
}
int dfsUtil(int s,bool visited[])
{
  visited[s]=true;
  pointC(vertices[s].x,vertices[s].y);
  cout<<s<<" ";
  sleep(1);
  list<int>::iterator i;
  for(i=adj[s].begin();i!=adj[s].end();i++)
  {
    if(!visited[*i])
    {
      dfsUtil(*i,visited);
    }
  }
}
int pointC(int x,int y)
{
  glColor3f(1.0,0.0,0.0);
  glPointSize(10.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}
