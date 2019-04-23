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

struct Point p1;
struct Point p2;
struct Point p3;
struct Point p4;
int count = 0;
int tx = 0,ty = 0;
int status = 0;

void render(){

    // handleTransforms(0);
    glBegin(GL_QUADS);
        glVertex2i(p1.x,p1.y);
        glVertex2i(p2.x,p2.y);
        glVertex2i(p3.x,p3.y);
        glVertex2i(p4.x,p4.y);
    glEnd();

    glFlush();

}

void reset(){
    if(status == 1){
        status = 0;
        p1.x -= tx;
        p1.y -= ty;
        

        p2.x -= tx;
        p2.y -= ty;
        

        p3.x -= tx;
        p3.y -= ty;
        

        p4.x -= tx;
        p4.y -= ty;
        
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutPostRedisplay();    
    }
}
void Translate(){
    status = 1;
    cout<<"\nEnter Translateing Distance In X Dir: ";
    cin>>tx;

    cout<<"\nEnter Translateing Distance In Y Dir: ";
    cin>>ty;

    p1.x += tx;
    p1.y += ty;
    

    p2.x += tx;
    p2.y += ty;
    

    p3.x += tx;
    p3.y += ty;
    

    p4.x += tx;
    p4.y += ty;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}
void MainMenu(int choice){

    switch(choice){
        case 1:
                Translate();
               
                break;
        case 2:
                break;
        case 3:
                break;
        case 4:
                exit(0);
                break;                        
    }
}

void keyPressed (unsigned char key, int x, int y) {  

    if(key == 'c' || key == 'C'){
        reset();
    }

}  
void mouse(int button,int state,int x,int y){
    
    if(count < 4){
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        int x1 = 2*x - 400;
        int y1 = 400 -2*y;

        if(count == 0){
            p1.x = x1;
            p1.y = y1;
        }else if(count == 1){
            p2.x = x1;
            p2.y = y1;
        }else if(count == 2){
            p3.x = x1;
            p3.y = y1;
        }else if(count == 3){
            p4.x = x1;
            p4.y = y1;
        }else{
            
        }
        count++;

    }

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        reset();
    }
    
}

void Init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400,400,-400,400);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
}


int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400,400);
    glutCreateWindow("2D Transformation");
    Init();
    glutCreateMenu(MainMenu);
    glutAddMenuEntry("Translate",1);
    glutAddMenuEntry("Scale",2);
    glutAddMenuEntry("Rotate",3);
    glutAddMenuEntry("Exit",4);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(render);
    glutMouseFunc(mouse);
        glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
    // glutTimerFunc(1000,handleTransforms,0);
    glutMainLoop();
    return 0;

}