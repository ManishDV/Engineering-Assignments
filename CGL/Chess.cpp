#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

struct Point{
    int x;
    int y;
};

struct Color{
    float R;
    float G;
    float B;
    
};

struct Color oldColor = {1.0,1.0,1.0};
struct Color newColor = {0.0,0.0,0.0};

struct Point p1;
struct Point p2;
struct Point p3;
struct Point p4;

struct Point m1;
struct Point m2;

struct Point m3;
struct Point m4;

int first;
int last;
int count = 0;

int sign(int d){
    if(d < 0)return -1;
    else if(d > 0)return 1;
    else return 0;
}
void putpixel(int x,int y){
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();    
}

Point midpoint(Point p1,Point p2){

    Point p;
    p.x = (p1.x + p2.x) / 2;
    p.y = (p1.y + p2.y) / 2;
    
    return p;

}

Color getPixelColor(int x,int y){
    Color temp;
    glReadPixels(x+300,300+y,1,1,GL_RGB,GL_FLOAT,&temp);
    return temp;
}


void setPixelColor(int x,int y,Color color){
        glColor3f(color.R,color.G,color.B);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();   
        glFlush(); 
}


void floodFill(int x,int y,Color old,Color New){
    Color current = getPixelColor(x,y);
    
    if(current.R == old.R && current.G == old.G &&current.B == old.B){
        setPixelColor(x,y,New);
        floodFill(x+1,y,old,New);
        floodFill(x,y-1,old,New);
        floodFill(x-1,y,old,New);
        floodFill(x,y+1,old,New);

    }

}
void DDA(int x1,int y1,int x2,int y2){
    float DX = x2 - x1;
    float DY = y2 -y1;

    float x = x1;
    float y = y1;
    // glPointSize(2.0);
    float steps = 0;
    if(abs(DX) > abs(DY))
        steps = abs(DX);
    else
    {
            steps = abs(DY);
    }

    float xInc = DX / steps;
    float yInc = DY / steps;

    for(int i = 0;i <= steps;i++){
        putpixel(x,y);
        x = x+xInc;
        y = y+yInc;
    }   
    
     glFlush();   
}

void mouse(int button,int state,int x,int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        glPointSize(1.0);
        floodFill(x - 300,300 - y,oldColor,newColor);
    }

}

Point rotate(Point p){
    // p.x = p.x - first;
    int orgx = p.x;
    // p.y = p.y - last;

    double angle = (45 * 3.14 )/ 180;

    p.x = p.x * cos(angle) - p.y * sin(angle);
    p.y = orgx * sin(angle) + p.y * cos(angle);
    
    // p.x = p.x + first;
    // p.y = p.y + last;

    return p;
}
void render(){
     glClear(GL_COLOR_BUFFER_BIT);
    DDA(-600,0,600,0);
     cout<<"\nEnter Bottom Left Co-ordinates of Chess Board: ";
     cin>>p1.x>>p1.y;

     cout<<"\nEnter Top Right Co-ordinates of Chess Board: ";
     cin>>p2.x>>p2.y;
     first = p1.x;
     last = p1.y;
     p3 = {p1.x,p2.y};
     p4 = {p2.x,p1.y};
     
     
     
     p1 = rotate(p1);
     p2 = rotate(p2);
     p3 = rotate(p3);
     p4 = rotate(p4);
     
     
     DDA(p1.x,p1.y,p3.x,p3.y);
     DDA(p3.x,p3.y,p2.x,p2.y);
     DDA(p2.x,p2.y,p4.x,p4.y);
     DDA(p4.x,p4.y,p1.x,p1.y);
     
     m1 = midpoint(p1,p3);
     m2 = midpoint(p4,p2);

     m3 = m1;
     m4 = m2;
     cout<<"\nm1.X: "<<m1.x<<"\t m1.Y: "<<m1.y;
     cout<<"\nm2.X: "<<m2.x<<"\t m2.Y: "<<m2.y;
     DDA(m1.x,m1.y,m2.x,m2.y);

     m1 = midpoint(m1,p3);
     m2 = midpoint(m2,p2);

     DDA(m1.x,m1.y,m2.x,m2.y);
      
     m1 = midpoint(m3,p1);
     m2 = midpoint(m4,p4);

     DDA(m1.x,m1.y,m2.x,m2.y);
      
     //For Vertical Lines 
    
     m1 = midpoint(p3,p2);
     m2 = midpoint(p1,p4);

     m3 = m1;
     m4 = m2;
    //  cout<<"\nm1.X: "<<m1.x<<"\t m1.Y: "<<m1.y;
    //  cout<<"\nm2.X: "<<m2.x<<"\t m2.Y: "<<m2.y;
     DDA(m1.x,m1.y,m2.x,m2.y);

     m1 = midpoint(m1,p3);
     m2 = midpoint(m2,p1);

     DDA(m1.x,m1.y,m2.x,m2.y);
      
     m1 = midpoint(m3,p2);
     m2 = midpoint(m4,p4);

     DDA(m1.x,m1.y,m2.x,m2.y);
      

     
    // bresenham(-100,100,100,-100);
    glFlush();

}

void Init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
}


int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("2D Transformation");
    Init();
    glutMouseFunc(mouse);
    // glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;

}