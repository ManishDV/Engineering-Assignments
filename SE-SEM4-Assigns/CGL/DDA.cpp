
#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
struct point
{
   GLfloat x;
   GLfloat y;
};

	static int count = 0;
	struct point point1;
	struct point point2;
	struct point start;
	
void DDA(point p1, point p2)
{
    GLfloat dx = p2.x - p1.x;
    GLfloat dy = p2.y - p1.y;

    GLfloat x1 = p1.x;
    GLfloat y1 = p1.y;

    GLfloat step = 0;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    GLfloat xInc = dx / step;
    GLfloat yInc = dy / step;

    glBegin(GL_POINTS);
    for (float i = 1; i <= step; i++)
    {
        glVertex2i(x1, y1);
        x1 += xInc;
        y1 += yInc;
    }
    glEnd();
    glFlush();
}

void render()
{
	point1.x = 100.0;
	point1.y = 50.0;
	point2.x = 200.0;
	point2.y = 150.0;
		
	cout<<"\nPoint1: "<<point1.x<<" "<<point1.y;
	cout<<"\nPoint2: "<<point2.x<<" "<<point2.y;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glPointSize(2.0);
	glEnable(GL_POINT_SMOOTH);	
	DDA(point1,point2);
	glFlush();
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	//glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,600,0,600);
	//glOrtho(0, 100, 0, 300, -1, 1); 
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400,400);
	glutInitWindowSize(600,600);
	glutCreateWindow("TESTING WINDOW");
	init();
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;	

}