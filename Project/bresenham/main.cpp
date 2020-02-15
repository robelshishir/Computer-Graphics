#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<stdio.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  gluOrtho2D(0.0,400.0,0.0,400.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}

int x1,y1,x2,y2;
int	dx, dy, pk[100],		//decision parameter
  	x,y,
  	k;
void line()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1.0 ,1.0, 1.0);
  dx=x2-x1;
  dy=y2-y1;
  x=x1;
  y=y1;
  int robel=0;
  //setPixel(x1, y1);//plot first point
  glBegin(GL_POINTS);
  glVertex2s(x1,y1);

//Your Code Here??
k=2*dy-dx;
while(x<x2&&y<y2)
{
    robel++;
    if(k>0)
    {
        k=k+(2*dy)-(2*dx);
        x=x+1;
        y=y+1;
    }
    else
    {
        k=k+(2*dy);
        x=x+1;
        y=y;
    }
 //setPixel( x, y );
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    printf("%d     %d    %d\n",robel,x,y);
}
  glutSwapBuffers();
}
  //glFlush();



int main(int argc,char **argv){

    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    glutInit(&argc,argv);

    //glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc( line );
    glutMainLoop();
    return 0;
}

