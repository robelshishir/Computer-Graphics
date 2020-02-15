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
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,400.0,0.0,400.0);
}

int x1,y1,x2,y2;
int	dx, dy, pk[100],x,y,k;

void line()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1.0 ,1.0, 1.0);
    dx=x2-x1;
    dy=y2-y1;
    x=x1;
    y=y1;
    int robel=0;
    glBegin(GL_POINTS);
    glVertex2s(x1,y1);

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

        glColor3f (1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        printf("%d     %d    %d\n",robel,x,y);
    }
  glutSwapBuffers();
}

int main(int argc,char **argv)
{

    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc(line);
    glutMainLoop();
    return 0;
}
