#include<stdlib.h>
#include<stdio.h>
#include<gl/glut.h>

float index = .0f;
int count1 = 0;
int count2 = 0;
void keyboard(unsigned char key,int x,int y);
void display(void);
void resharp(int,int);
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(300,400);
    glutInitWindowPosition(50,50);
    glutCreateWindow("GLUT Test");

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    // glViewport(0,0,400,300);
    glClearColor(.3f,.4f,.5f,1.f);
    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(&display);
    glutIdleFunc(&display);
    glutReshapeFunc(&resharp);
    glutMainLoop();

    return 0;
}

void keyboard(unsigned char key,int x,int y){
    
}

void resharp(int width,int height){
    glViewport(0,0,width,height);
}
void display(){
   char title[100];
    sprintf(title,"count1:%d,count2:%d",count1,count2);
    glutSetWindowTitle(title);

    index += 0.1f;
    if(index>360)
        index = .0f;

    ++count1;
    if(count1>1000){
     count1 = 0;
     ++count2;   
    }
     glClear(GL_COLOR_BUFFER_BIT);

    glViewport(150,200,150,200);
    glColor3f(1.0f, 0.0f, 0.0f);
    glLoadIdentity();
    glRotated((GLdouble)index,.0,1.,.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, -0.5f,.0F);
    glVertex3f(0.5f, -0.5f,.0F);
    glVertex3f(.0F, 0.5f,.0F);
    glEnd();

    glColor3f(.5f,.7f,.0f);
    glViewport(0,0,20,20);
    glLoadIdentity();
    glBegin(GL_POLYGON);
    glVertex3f(1.f, 1.f,.0F);
    glVertex3f(1.f, -1.f,.0F);
    glVertex3f(-1.f, -1.f,.0F);
    glVertex3f(-1.f, 1.f,.0F);
    glEnd();
    // glFlush();
    glutSwapBuffers();
}