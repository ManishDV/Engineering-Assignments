#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;
struct point
{
   GLint x;
   GLint y;
};
struct COLOR
{
  public:
    float r, g, b;
};
	
	static int count = 0;
	struct point point1;
	struct point point2;
	struct point start;
	bool flag = true;
	COLOR newcolor;
	COLOR oldcolor = {1.0f, 1.0f, 1.0f};

COLOR getPixelColor(int x, int y)
{
    COLOR temp;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &temp); // Get the Pixel Color
    return temp;
}

void setPixelColor(int X, int Y, COLOR color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(X, Y);
    glEnd();
    glFlush();
}


void seedFill(int X, int Y, COLOR oldColor, COLOR fillColor)
{
    COLOR current;
    current = getPixelColor(X, Y);
    if (current.r == oldColor.r && current.g == oldColor.g && current.b == oldColor.b)
    {
        setPixelColor(X, Y, fillColor);
        seedFill(X + 1, Y, oldColor, fillColor);
        seedFill(X, Y - 1, oldColor, fillColor);
        seedFill(X - 1, Y, oldColor, fillColor);
        seedFill(X, Y + 1, oldColor, fillColor);
    }
}

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
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	//glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,600,0,600);
	//glOrtho(0, 100, 0, 300, -1, 1); 
}


void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	//glPointSize(2.0);
	//glEnable(GL_POINT_SMOOTH);	
	glFlush();
}

void mouse(int button,int states,int x,int y)
{
	
	if(flag)
	{
	   	if(button == GLUT_LEFT_BUTTON && states == GLUT_DOWN && count == 0)
		{
	    		point1.x = x;
	   	 	point1.y = 600-y;
	    		start = point1;
	    		count++;	
		}
		else if(button == GLUT_LEFT_BUTTON && states == GLUT_DOWN)
		{
	    		cout<<"\nX & Y: "<<point1.x<<" "<<point1.y;
	    		point2.x = x;
	    		point2.y = 600-y;
	    		DDA(point1,point2);
	    		point1 = point2;
		}
	
		if(button == GLUT_RIGHT_BUTTON && states == GLUT_DOWN)
		{
			DDA(start,point2);

			flag = false;					
		}

	}
	else
	{
		if(button == GLUT_LEFT_BUTTON && states == GLUT_DOWN)
		{
			glColor3f(1.0, 0.0, 0.0); // Red
        	        glRecti(10, 30, 60, 10);
            		glColor3f(0.0, 1.0, 0.0); // Green
            		glRecti(90, 30, 140, 10);
            		glColor3f(0.0, 0.0, 1.0); // Blue
            		glRecti(170, 30, 220, 10);
            		glColor3f(1.0, 1.0, 0.0); // Red-green
            		glRecti(250, 30, 300, 10);
            		glColor3f(0.0, 1.0, 1.0); // Green-blue
            		glRecti(330, 30, 380, 10);
            		glColor3f(1.0, 0.0, 1.0); // Blue-red
            		glRecti(410, 30, 460, 10);
			newcolor = getPixelColor(x, 600 - y);
			glFlush();	
		}
	
		if(button == GLUT_RIGHT_BUTTON && states == GLUT_DOWN)
		{
			 seedFill(x, 600 - y, oldcolor,newcolor);
		}
	
	}
	glFlush();	
}



int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400,400);
	glutInitWindowSize(600,600);
	glutCreateWindow("Assignment 3");
	init();
	glutDisplayFunc(render);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;	

}
