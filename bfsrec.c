#include<stdio.h>
	#include<math.h>
	#include<GL/glut.h>
	#include<GL/gl.h>


	int i,n,x[20],y[20],j,edge1[20],edge2[20],e,a[20][20],v,q[20],visited[20],f=0,r=-1,pi[20];

	void init() {  
		  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		  glutInitWindowPosition(0,0);
		  glutInitWindowSize(640, 480);
		  glutCreateWindow("BFS");
		  glClearColor(0.0,0.0,0.0,0);
		  glColor3f(1.0,1.0,1.0);
		  glPointSize(15.0);
		  gluOrtho2D(-320,320,-240,240);
		}
	void delay(int x)
	{   int i=0,j=0;
	    for(i=0;i<x;i++){for(j=0;j<200000;j++){}}
	}	
	void bfs(int v) {
		for (i=0;i<n;i++)
		  if(a[v][i] && !visited[i]){
		   q[++r]=i;
		   pi[i]=v;
		   visited[i]=1;
		   glColor3f(1.0,0.0,0.0);
	   	   glBegin(GL_LINES);
		   	glVertex2i(x[i],y[i]);
			glVertex2i(x[pi[i]],y[pi[i]]);
		   glEnd();
		   glFlush();
		   delay(3000);
		   }
		if(f<=r) {
			//visited[q[f]]=1;
			bfs(q[f++]);
		}
	}

	int main(int argc,char **argv)
	{
		printf("\nNumber of vertices:");
		scanf("%d",&n);
		printf("\nRead vertices:\n");
		for(i=0;i<n;i++){
			scanf("%d%d",&x[i],&y[i]);
			q[i]=0;
			visited[i]=0;
			pi[i]=0;
		}
		printf("\nGraph in matrix form:\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("(%d,%d):",i,j);
				scanf("%d",&a[i][j]);
				printf("\n");
			}
		}
		glutInit(&argc, argv);
		init();
		glClear(GL_COLOR_BUFFER_BIT);
		for(i=0;i<n;i++){
		glPointSize(15.0);
		glBegin(GL_POINTS);
			glVertex2i(x[i],y[i]);
		glEnd();
		glPointSize(6.0);
		glRasterPos2f(x[i]+10,y[i]+10);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,i+48);
		glFlush();
		}
		glColor3f(1.0,1.0,1.0);
		glPointSize(5.0);
		for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			if(a[i][j]){
			glBegin(GL_LINES);
				glVertex2i(x[i],y[i]);
				glVertex2i(x[j],y[j]);
			glEnd();
			glFlush();
			}
		}}
		printf("\n Enter the starting vertex:");
		scanf("%d",&v);
		bfs(v);
		printf("\n The node which are reachable are:\n");
	 	for(i=1;i<n;i++){
	  		if(visited[i]){
	   			printf("%d\t",i);
	   		}
	  		else
	   			printf("\n Bfs is not possible");
	   	}
		glutMainLoop();
		return 0;
	}

