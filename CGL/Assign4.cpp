#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;
struct point{
        GLfloat x;
        GLfloat y;
};

struct color{
    GLfloat R;
    GLfloat G;
    GLfloat B;
};
color oldcolor = {1.0f, 1.0f, 1.0f};
color newcolor = {0.0f,0.0f,0.0f};

color getPixelColor(int x, int y)
{
    color temp;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &temp); // Get the Pixel Color
    return temp;
}

void setPixelColor(int X, int Y, color color)
{
    glColor3f(color.R, color.G, color.B);
    glBegin(GL_POINTS);
    glVertex2i(X, Y);
    glEnd();
    glFlush();
}

void seedFill(int X, int Y, color oldColor, color fillColor)
{
    color current;
    current = getPixelColor(X, Y);
    if (current.R == oldColor.R && current.G == oldColor.G && current.B == oldColor.B)
    {
        setPixelColor(X, Y, fillColor);
        seedFill(X + 1, Y, oldColor, fillColor);
        seedFill(X, Y - 1, oldColor, fillColor);
        seedFill(X - 1, Y, oldColor, fillColor);
        seedFill(X, Y + 1, oldColor, fillColor);
    }
}
void DDA(GLfloat x1, GLfloat y1,GLfloat x2,GLfloat y2)
{
    GLfloat dx = x2 - x1;
    GLfloat dy = y2 - y1;

    GLfloat x = x1;
    GLfloat y = y1;

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
        glVertex2i(x, y);
        x += xInc;
        y += yInc;
    }
    glEnd();
    glFlush();
}
void mouse(int button,int states,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && states == GLUT_DOWN)
    {
        seedFill(x, 600 - y,oldcolor,newcolor);
    }
    
	glFlush();	
}

// point rotate(point p)
// {   

//     p.x = p.x * cos(45) - p.y * sin(45);
//     p.y = p.x * sin(45) + p.y * cos(45);

//     p.x += 10;
//     p.y += 10;
    
//     return p;
// }       
void render(){

    point p1,p2;
    
    cout<<"\nEnter Bottom Left Point Co-ordinates: ";
    cin>>p1.x>>p1.y;

    cout<<"\nEnter Top Right Point Co-ordinates: ";
    cin>>p2.x>>p2.y;
    
    point p3 = {p1.x,p2.y};
    point p4 = {p2.x,p1.y};


    float vlen = sqrt(pow(p1.x - p1.x,2)+pow(p2.y - p1.y,2));    
    float hlen = sqrt(pow(p2.x - p1.x,2)+pow(p2.y - p2.y,2));

    DDA(p1.x,p1.y,p3.x,p3.y);
    DDA(p3.x,p3.y,p2.x,p2.y);
    DDA(p2.x,p2.y,p4.x,p4.y);
    DDA(p4.x,p4.y,p1.x,p1.y);
   

    DDA(p1.x,p1.y+(0.25*vlen),p4.x,p4.y+(0.25*vlen));
    DDA(p1.x,p1.y+(0.50*vlen),p4.x,p4.y+(0.50*vlen));
    DDA(p1.x,p1.y+(0.75*vlen),p4.x,p4.y+(0.75*vlen));
    
    DDA(p1.x+(0.25*hlen),p1.y,p3.x+(0.25*hlen),p3.y);
    DDA(p1.x+(0.50*hlen),p1.y,p3.x+(0.50*hlen),p3.y);
    DDA(p1.x+(0.75*hlen),p1.y,p3.x+(0.75*hlen),p3.y);


    glFlush();
}


void init(){
   
	glClearColor(1.0,1.0,1.0,0.0);
	//glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);
	gluOrtho2D(0,600,0,600);
	//glOrtho(0, 100, 0, 300, -1, 1);
}
int main(int argc,char** argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowPosition(400,400);
   glutInitWindowSize(600,600);
   glutCreateWindow("Chess");
   init();
   glutMouseFunc(mouse);
   glutDisplayFunc(render);
   glutMainLoop();
    return 0;    
}
