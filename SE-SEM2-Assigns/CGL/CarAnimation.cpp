#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

int width = 0;
int height = 0;
int cx = 70;
int cy = 0;
int startPos = 0;
int count = 0;
int radius = 70;
int angle = 0;
int first = 0;
int last = 0;
// float angle = 0.9;
struct Point{
    int x;
    int y;
};
void reshape(int w,int h){
    width = w;
    height = h;
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w,w,-h,h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DrawDDA(Point p1, Point p2)
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

void drawCircle(int cx,int cy,int radius){

    int x1 = 0;
    int y1 = radius;
    float d = 3- 2*radius;
    
    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    while(x1 <= y1)
    {
        if(d  < 0){
            x1++;
            d = d+4*x1+6;
        }else{
            x1++;
            y1--;
            d = d+4*(x1-y1)+10;
        }
        glVertex2i(cx+x1,cy+y1);
        glVertex2i(cx+y1,cy+x1);
        glVertex2i(cx+y1,cy-x1);
        glVertex2i(cx+x1,cy-y1);
        glVertex2i(cx-x1,cy-y1);
        glVertex2i(cx-y1,cy-x1);
        glVertex2i(cx-y1,cy+x1);
        glVertex2i(cx-x1,cy+y1);
    
    }
    
    glEnd();
}
struct Point rotate(int x,int y){
       
       
       struct Point p;
       
       int orgy = y;

       x = x - first;
       int orgx = x;
       y = y - last; 
       
       x = x * cos(angle)- y*sin(angle);
       y = (orgx * sin(angle)) + y*cos(angle);

       x = x+first;
       y = y+last; 
       p = {x,y};
       return p; 


}

void drawSpike(int dist){
        cout<<"\nAngle: "<<angle;
        if(angle < 0.1){
            angle = 0.9;
        }
        first = -width+dist;
        last = 10;
        struct Point p1 = rotate(-width+dist,radius);
         struct Point p2 = rotate(-width+dist,-radius);

         struct Point p3 = rotate(-width+dist+radius,10);
         struct Point p4 = rotate(-width+dist-radius,10);
         


        DrawDDA(p1,p2);
        DrawDDA(p3,p4);
        

       
}
void render(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glColor3f(1.0,0.0,0.0);
    //Draw Car
    glBegin(GL_QUADS);
        glVertex2i(-width+startPos,0);
        glVertex2i(-width+startPos,300);
        glVertex2i(-width+startPos+400,250);
        glVertex2i(-width+startPos+400,0);
    glEnd();
    glPointSize(5.0);
    glColor3f(0.0,0.0,0.0);

   //Draw Wheels
        drawCircle(-width+cx,10, 70);
        drawCircle(-width+cx+250,10,70);

    //Draw Spikes
        glPointSize(3.0);
        drawSpike(cx);
        drawSpike(cx+250);
                
    // glViewport(0, 0, width, height);
    glFlush();
}

void Init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(-width,width,-height,height);
    glMatrixMode(GL_MODELVIEW);
    glFlush();
}

void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(1000/10,timer,0);
    startPos += 10;
    cx += 10;
    angle += 45;
    if(-width+startPos == width){
        startPos = 0;
        cx = 70;
        // count = 0;
    }
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(900,600);
    glutCreateWindow("Car Animation");
    Init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutTimerFunc(1000,timer,0);
    glutMainLoop();
    return 0;
}
