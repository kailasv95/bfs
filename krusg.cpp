#include <bits/stdc++.h>
#include <GL/glut.h>
#include <unistd.h>
using namespace std;
//variables for kruskal

int ne,nv;
typedef pair<int,int> ipair;
vector< pair<int,ipair> > edges;
int *parent,*rank;
int merge(int,int v);
int kruskal();
int find(int u);
int make_disjoint_set(int n);
int addedge(int s,int d,int w);

//variables for graphics
struct point
{
  int x,y;
};
struct line
{
  int s,d,w;
  int sx,sy,dx,dy;
};
int j=0;
struct point* vertices;
struct line* edge;
void drawnode(int x,int y);
void drawnodeC(int p);
void drawedge();
void drawedgeC(int u,int v);
void render(int button,int state,int x,int y);
int main(int argc,char** argv)
{
  int s,d,w;
  cout<<"Enter the no.of vertices\n";
  cin>>nv;
  cout<<"Enter the no.of edges\n";
  cin>>ne;
  vertices=new struct point[nv];
  edge=new struct line[ne];
  cout<<"Enter the edges\n";
  for(int i=0;i<ne;i++)
  {
    cin>>s>>d>>w;
    edge[i].s=s;
    edge[i].d=d;
    edge[i].w=w;
    addedge(s,d,w);
  }
  glutInit(&argc,argv);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(0,0);
  glutCreateWindow("kruskal");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0.0,600.0,600.0,0.0);
  glutMouseFunc(render);
  glutMainLoop();
  return 0;
  // kruskal();
}
int addedge(int s,int d,int w)
{
  edges.push_back({w,{s,d}});
  return 0;
}
int kruskal()
{
  int mst_wt=0;
  sort(edges.begin(),edges.end());
  make_disjoint_set(nv);
  vector< pair<int,ipair> >::iterator it;
  for(it=edges.begin();it!=edges.end();it++)
  {
    int u=it->second.first;
    int v=it->second.second;
    int set_u=find(u);
    int set_v=find(v);
    if(set_v!=set_u)
    {
      drawnodeC(u);
      drawnodeC(v);
      drawedgeC(u,v);
      cout<<u<<" "<<v<<endl;
      sleep(1);
      mst_wt+=it->first;
      merge(set_u,set_v);
    }
  }
}
int make_disjoint_set(int n)
{
  parent=new int[n+1];
  rank=new int[n+1];
  memset(rank,0,n+1);
  for(int i=0;i<n+1;i++)
  {
    parent[i]=i;
  }
}
int find(int u)
{
  if(u!=parent[u])
  {
    parent[u]=find(parent[u]);
  }
  return parent[u];
}
int merge(int x,int y)
{
  x=find(x);
  y=find(y);
  if(rank[x]>rank[y])
  {
    parent[y]=x;
  }
  else
  {
    parent[x]=y;
  }
  if(rank[x]==rank[y])
  {
    rank[y]++;
  }
}
void render(int button,int state,int x,int y)
{
  if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
  {
    if(j<nv)
    {
      drawnode(x,y);
    }
  }
  else if(button==GLUT_RIGHT_BUTTON)
  {
    drawedge();
  }
  else if(button==GLUT_MIDDLE_BUTTON)
  {
    kruskal();
  }
}
void drawnode(int x,int y)
{
  vertices[j].x=x;
  vertices[j++].y=y;
  glColor3f(1.0,1.0,1.0);
  glPointSize(5.0);
  glBegin(GL_POINTS);
    glVertex2i(x,y);
  glEnd();
  glRasterPos2f(x+10,y+10);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,j+47);
  glFlush();
}
void drawedge()
{
  glPointSize(3.0);
  for(int i=0;i<ne;i++)
  {
    edge[i].sx=vertices[edge[i].s].x;
    edge[i].sy=vertices[edge[i].s].y;
    edge[i].dx=vertices[edge[i].d].x;
    edge[i].dy=vertices[edge[i].d].y;
    glBegin(GL_LINES);
      glVertex2i(edge[i].sx,edge[i].sy);
      glVertex2i(edge[i].dx,edge[i].dy);
    glEnd();
  }
  glFlush();
}
void drawnodeC(int p)
{
  glPointSize(8.0);
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POINTS);
    glVertex2i(vertices[p].x,vertices[p].y);
  glEnd();
  glFlush();
}
void drawedgeC(int u,int v)
{
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINES);
   glVertex2i(vertices[u].x,vertices[u].y);
   glVertex2i(vertices[v].x,vertices[v].y);
  glEnd();
  glFlush();
}
