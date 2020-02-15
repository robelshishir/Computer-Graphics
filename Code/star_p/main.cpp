#include <GL/gl.h>
#include <GL/glut.h>

void display (void)

{
    glClear (GL_COLOR_BUFFER_BIT);

    //top
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(100,400);
    glVertex2d(500,500);
    glVertex2d(100,600);
    glVertex2d(0,1000);
    glVertex2d(-100,600);
    glVertex2d(-500,500);
    glVertex2d(-100,400);
    glVertex2d(0,0);
    glEnd();

    //left
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2d(-400,100);
    glVertex2d(-500,500);
    glVertex2d(-600,100);
    glVertex2d(-1000,0);
    glVertex2d(-600,-100);
    glVertex2d(-500,-500);
    glVertex2d(-400,-100);
    glVertex2d(0,0);
    glEnd();

    //down
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(100,-400);
    glVertex2d(500,-500);
    glVertex2d(100,-600);
    glVertex2d(0,-1000);
    glVertex2d(-100,-600);
    glVertex2d(-500,-500);
    glVertex2d(-100,-400);
    glVertex2d(0,0);
    glEnd();

    //right
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    glVertex2d(400,100);
    glVertex2d(500,500);
    glVertex2d(600,100);
    glVertex2d(1000,0);
    glVertex2d(600,-100);
    glVertex2d(500,-500);
    glVertex2d(400,-100);
    glVertex2d(0,0);
    glEnd();

    glFlush();

}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000,1000,-1000,1000);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("star practice");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return(0);
}
