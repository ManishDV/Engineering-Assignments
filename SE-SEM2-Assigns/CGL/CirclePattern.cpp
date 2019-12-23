#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;

void DrawCircle(float cx,float cy,int radius){

    float d = 3-2*radius;
    float X =0,Y = radius;
    
    glBegin(GL_POINTS);
    
    while(X <= Y){
        if(d < 0){
            X++; 
            d = d+4*X+6;
        }else{
             X++;
             Y--;
             d = d + 4*(X - Y)+10;                
        } 
        glVertex2i(cx+X,cy+Y);
        glVertex2i(cx+Y,cy+X);
        glVertex2i(cx+Y,cy-X);
        glVertex2i(cx+X,cy-Y);
        glVertex2i(cx-X,cy-Y);
        glVertex2i(cx-Y,cy-X);
        glVertex2i(cx-Y,cy+X);
        glVertex2i(cx-X,cy+Y);
        
    }   
    glEnd();
    glFlush();
}
 
void render(){

        glPointSize(1.0);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_LINE_SMOOTH_HINT);
        int radius = 0;
        cout<<"\nEnter Radius Of The Circle: ";
        cin>>radius;

        DrawCircle(0,0,radius);
        DrawCircle(0,0,radius/2);
        // DrawCircle(-radius,0,radius/2);
        DrawCircle(radius,0,radius/2);
        DrawCircle(-radius,0,radius/2);
        DrawCircle(radius/2,radius * 0.87,radius/2);// Circle 5
        DrawCircle(-radius/2,-radius * 0.87,radius/2);// Circle 5
        DrawCircle(-radius/2,radius * 0.87,radius/2);// Circle 5
        DrawCircle(radius/2,-radius * 0.87,radius/2);// Circle 5
        
    glFlush(); 

}




void Init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0,1.0,1.0);
    gluOrtho2D(-400,400,-400,400);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFlush();
}
int main(int argc,char** argv){
     glutInit(&argc,argv);
     glutInitWindowPosition(400,400);
     glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
     glutInitWindowSize(600,600);
     glutCreateWindow("Circle Pattern");
     Init();
     glutDisplayFunc(render);
     glutMainLoop();
     return 0;
}