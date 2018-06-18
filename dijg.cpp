#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
#define INF 0x3f3f3f3f
int ne,nv;
typedef pair<int,int> ipair;
list<pair<int,int> > *adj;
int addedge(int s,int d,int w);
int dijikstra();
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
void drawnodeC(int p,int wt);
void drawedge();
void render(int button,int state,int x,int y);

int main(int argc,char** argv)
{
  int s,d,w;
  cout<<"Enter the no.of vertices\n";
  cin>>nv;
  cout<<"Enter the no.of edges\n";
  cin>>ne;
  adj=new list<ipair>[nv];
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
}
int addedge(int s,int d,int w)
{
  adj[s].push_back(make_pair(d,w));
  adj[d].push_back(make_pair(s,w));
  return 0;
}
int dijikstra()
{
  int src;
  cout<<"Enter the source vertex\n";
  cin>>src;
  vector<int> dist(nv,INF);
  priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
  list<pair<int,int> >:: iterator it;
  pq.push(make_pair(0,src));
  dist[src]=0;
  while(!pq.empty())
  {
    int u=pq.top().second;
    pq.pop();
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
      int v=(*it).first;
      int wt=(*it).second;
      if(dist[v]>dist[u]+wt)
      {
        dist[v]=dist[u]+wt;
        pq.push(make_pair(dist[v],v));
      }
    }
  }
  for(int i=0;i<nv;i++)
  {
    drawnodeC(i,dist[i]);
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
    dijikstra();
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
void drawnodeC(int p,int wt)
{
  glPointSize(15.0);
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POINTS);
    glVertex2i(vertices[p].x,vertices[p].y);
  glEnd();
  glColor3f(1.0,1.0,1.0);
  glRasterPos2f(vertices[p].x,vertices[p].y);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,wt+48);
  glFlush();
}
