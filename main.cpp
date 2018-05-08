/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
// ----------------------------------------------------------
// Includes
// ----------------------------------------------------------
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;


void createCube(float x, float y, float z){
    glPushMatrix();
        glTranslated(x,y,z);

        //Multi-colored side - FRONT
        glBegin(GL_POLYGON);

        glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
        glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
        glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
        glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple

        glEnd();

        // White side - BACK
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  1.0, 1.0 );
        glVertex3f(  0.5, -0.5, 0.5 );
        glVertex3f(  0.5,  0.5, 0.5 );
        glVertex3f( -0.5,  0.5, 0.5 );
        glVertex3f( -0.5, -0.5, 0.5 );
        glEnd();

        // Purple side - RIGHT
        glBegin(GL_POLYGON);
        glColor3f(  1.0,  0.0,  1.0 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( 0.5,  0.5, -0.5 );
        glVertex3f( 0.5,  0.5,  0.5 );
        glVertex3f( 0.5, -0.5,  0.5 );
        glEnd();

        // Green side - LEFT
        glBegin(GL_POLYGON);
        glColor3f(   0.0,  1.0,  0.0 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        // Blue side - TOP
        glBegin(GL_POLYGON);
        glColor3f(   0.0,  0.0,  1.0 );
        glVertex3f(  0.5,  0.5,  0.5 );
        glVertex3f(  0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glEnd();

        // Red side - BOTTOM
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  0.0,  0.0 );
        glVertex3f(  0.5, -0.5, -0.5 );
        glVertex3f(  0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();
    glPopMatrix();
    //glutSwapBuffers();
}


// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // Reset transformations
  glLoadIdentity();

  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included


//  createCube(0,0,0);
//  createCube(1,1,0);

    createCube( 1.0 ,  0.0 ,  1 );
    createCube( 0.30901699437494745 ,  0.9510565162951535 ,  1 );
    createCube( -0.8090169943749473 ,  0.5877852522924732 ,  1 );
    createCube( -0.8090169943749476 ,  -0.587785252292473 ,  1 );
    createCube( 0.30901699437494723 ,  -0.9510565162951536 ,  1 );
    createCube( 2.0 ,  0.0 ,  2 );
    createCube( 0.5000000000000002 ,  0.8660254037844387 ,  2 );
    createCube( 0.49999999999999956 ,  -0.8660254037844384 ,  2 );
    createCube( 0.19098300562505244 ,  -0.587785252292473 ,  2 );

  glFlush();
  glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //  Request display update
  glutPostRedisplay();

}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // Create window
  glutCreateWindow("Awesome Cube");

  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);

  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);

  //  Pass control to GLUT for events
  glutMainLoop();

  //  Return to OS
  return 0;

}