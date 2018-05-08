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

/*
/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */
/*
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        //glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    /*
    glPushMatrix();
        glTranslated(0,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.2,0.8,slices,stacks);
    glPopMatrix();*/
/*
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */
/*
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
*/


//
// File:        mycube.c
// Author:      Matt Daisley
// Created:     4/25/2012
// Project:     Source code for Make a Cube in OpenGL
// Description: Creates an OpenGL window and draws a 3D cube
//              That the user can rotate using the arrow keys
//
// Controls:    Left Arrow  - Rotate Left
//              Right Arrow - Rotate Right
//              Up Arrow    - Rotate Up
//              Down Arrow  - Rotate Down

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
double a = 90;

void drawLine(float x1, float y1, float z1, float x2, float y2, float z2){
    glPushMatrix();
        glLineWidth(2.5);
        glColor3f(1.0, 0.0, 0.0);
        glScalef(.03f,.03f,.03f);
        glBegin(GL_LINES);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
        glEnd();
    glPopMatrix();
}

void createCube(float x, float y, float z){
    glPushMatrix();
        glScalef(.03f,.03f,.03f);
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
glRotated(a,0,0,1);
createCube( 0 ,  0 ,  0 );
createCube( 6.0 ,  0.0 ,  5 );
drawLine( 0 , 0 , 0 , 6.0 , 0.0 , 5 );
createCube( 1.8541019662496847 ,  5.706339097770921 ,  5 );
drawLine( 0 , 0 , 0 , 1.8541019662496847 , 5.706339097770921 , 5 );
createCube( -4.854101966249684 ,  3.5267115137548393 ,  5 );
drawLine( 0 , 0 , 0 , -4.854101966249684 , 3.5267115137548393 , 5 );
createCube( -4.854101966249686 ,  -3.5267115137548384 ,  5 );
drawLine( 0 , 0 , 0 , -4.854101966249686 , -3.5267115137548384 , 5 );
createCube( 1.8541019662496834 ,  -5.706339097770922 ,  5 );
drawLine( 0 , 0 , 0 , 1.8541019662496834 , -5.706339097770922 , 5 );

createCube( 9.0 ,  0.0 ,  10 );
drawLine( 6.0 , 0.0 , 5 , 9.0 , 0.0 , 10 );
createCube( 6.927050983124842 ,  2.8531695488854605 ,  10 );
drawLine( 6.0 , 0.0 , 5 , 6.927050983124842 , 2.8531695488854605 , 10 );
createCube( 3.572949016875158 ,  1.7633557568774196 ,  10 );
drawLine( 6.0 , 0.0 , 5 , 3.572949016875158 , 1.7633557568774196 , 10 );
createCube( 3.572949016875157 ,  -1.7633557568774192 ,  10 );
drawLine( 6.0 , 0.0 , 5 , 3.572949016875157 , -1.7633557568774192 , 10 );
createCube( 6.9270509831248415 ,  -2.853169548885461 ,  10 );
drawLine( 6.0 , 0.0 , 5 , 6.9270509831248415 , -2.853169548885461 , 10 );
createCube( 4.854101966249685 ,  5.706339097770921 ,  10 );
drawLine( 1.8541019662496847 , 5.706339097770921 , 5 , 4.854101966249685 , 5.706339097770921 , 10 );
createCube( 2.781152949374527 ,  8.559508646656381 ,  10 );
drawLine( 1.8541019662496847 , 5.706339097770921 , 5 , 2.781152949374527 , 8.559508646656381 , 10 );
createCube( -0.5729490168751572 ,  7.46969485464834 ,  10 );
drawLine( 1.8541019662496847 , 5.706339097770921 , 5 , -0.5729490168751572 , 7.46969485464834 , 10 );
createCube( -0.5729490168751581 ,  3.9429833408935018 ,  10 );
drawLine( 1.8541019662496847 , 5.706339097770921 , 5 , -0.5729490168751581 , 3.9429833408935018 , 10 );
createCube( 2.781152949374526 ,  2.85316954888546 ,  10 );
drawLine( 1.8541019662496847 , 5.706339097770921 , 5 , 2.781152949374526 , 2.85316954888546 , 10 );
createCube( -1.8541019662496838 ,  3.5267115137548393 ,  10 );
drawLine( -4.854101966249684 , 3.5267115137548393 , 5 , -1.8541019662496838 , 3.5267115137548393 , 10 );
createCube( -3.9270509831248415 ,  6.379881062640299 ,  10 );
drawLine( -4.854101966249684 , 3.5267115137548393 , 5 , -3.9270509831248415 , 6.379881062640299 , 10 );
createCube( -7.281152949374526 ,  5.2900672706322585 ,  10 );
drawLine( -4.854101966249684 , 3.5267115137548393 , 5 , -7.281152949374526 , 5.2900672706322585 , 10 );
createCube( -7.281152949374526 ,  1.76335575687742 ,  10 );
drawLine( -4.854101966249684 , 3.5267115137548393 , 5 , -7.281152949374526 , 1.76335575687742 , 10 );
createCube( -3.9270509831248424 ,  0.6735419648693783 ,  10 );
drawLine( -4.854101966249684 , 3.5267115137548393 , 5 , -3.9270509831248424 , 0.6735419648693783 , 10 );
createCube( -1.8541019662496856 ,  -3.5267115137548384 ,  10 );
drawLine( -4.854101966249686 , -3.5267115137548384 , 5 , -1.8541019662496856 , -3.5267115137548384 , 10 );
createCube( -3.9270509831248432 ,  -0.6735419648693779 ,  10 );
drawLine( -4.854101966249686 , -3.5267115137548384 , 5 , -3.9270509831248432 , -0.6735419648693779 , 10 );
createCube( -7.281152949374528 ,  -1.7633557568774187 ,  10 );
drawLine( -4.854101966249686 , -3.5267115137548384 , 5 , -7.281152949374528 , -1.7633557568774187 , 10 );
createCube( -7.281152949374528 ,  -5.290067270632258 ,  10 );
drawLine( -4.854101966249686 , -3.5267115137548384 , 5 , -7.281152949374528 , -5.290067270632258 , 10 );
createCube( -3.927050983124844 ,  -6.379881062640299 ,  10 );
drawLine( -4.854101966249686 , -3.5267115137548384 , 5 , -3.927050983124844 , -6.379881062640299 , 10 );
createCube( 4.854101966249683 ,  -5.706339097770922 ,  10 );
drawLine( 1.8541019662496834 , -5.706339097770922 , 5 , 4.854101966249683 , -5.706339097770922 , 10 );
createCube( 2.7811529493745257 ,  -2.8531695488854614 ,  10 );
drawLine( 1.8541019662496834 , -5.706339097770922 , 5 , 2.7811529493745257 , -2.8531695488854614 , 10 );
createCube( -0.5729490168751585 ,  -3.942983340893502 ,  10 );
drawLine( 1.8541019662496834 , -5.706339097770922 , 5 , -0.5729490168751585 , -3.942983340893502 , 10 );
createCube( -0.5729490168751594 ,  -7.469694854648341 ,  10 );
drawLine( 1.8541019662496834 , -5.706339097770922 , 5 , -0.5729490168751594 , -7.469694854648341 , 10 );
createCube( 2.7811529493745253 ,  -8.559508646656383 ,  10 );
drawLine( 1.8541019662496834 , -5.706339097770922 , 5 , 2.7811529493745253 , -8.559508646656383 , 10 );

createCube( 11.0 ,  0.0 ,  15 );
drawLine( 9.0 , 0.0 , 10 , 11.0 , 0.0 , 15 );
createCube( 9.0 ,  2.0 ,  15 );
drawLine( 9.0 , 0.0 , 10 , 9.0 , 2.0 , 15 );
createCube( 7.0 ,  2.4492935982947064e-16 ,  15 );
drawLine( 9.0 , 0.0 , 10 , 7.0 , 2.4492935982947064e-16 , 15 );
createCube( 9.0 ,  -2.0 ,  15 );
drawLine( 9.0 , 0.0 , 10 , 9.0 , -2.0 , 15 );
createCube( 8.927050983124843 ,  2.8531695488854605 ,  15 );
drawLine( 6.927050983124842 , 2.8531695488854605 , 10 , 8.927050983124843 , 2.8531695488854605 , 15 );
createCube( 6.927050983124842 ,  4.853169548885461 ,  15 );
drawLine( 6.927050983124842 , 2.8531695488854605 , 10 , 6.927050983124842 , 4.853169548885461 , 15 );
createCube( 4.927050983124842 ,  2.853169548885461 ,  15 );
drawLine( 6.927050983124842 , 2.8531695488854605 , 10 , 4.927050983124842 , 2.853169548885461 , 15 );
createCube( 6.927050983124842 ,  0.8531695488854605 ,  15 );
drawLine( 6.927050983124842 , 2.8531695488854605 , 10 , 6.927050983124842 , 0.8531695488854605 , 15 );
createCube( 5.5729490168751585 ,  1.7633557568774196 ,  15 );
drawLine( 3.572949016875158 , 1.7633557568774196 , 10 , 5.5729490168751585 , 1.7633557568774196 , 15 );
createCube( 1.572949016875158 ,  1.7633557568774199 ,  15 );
drawLine( 3.572949016875158 , 1.7633557568774196 , 10 , 1.572949016875158 , 1.7633557568774199 , 15 );
createCube( 5.572949016875157 ,  -1.7633557568774192 ,  15 );
drawLine( 3.572949016875157 , -1.7633557568774192 , 10 , 5.572949016875157 , -1.7633557568774192 , 15 );
createCube( 4.190983005625052 ,  0.13875727571288787 ,  15 );
drawLine( 3.572949016875157 , -1.7633557568774192 , 10 , 4.190983005625052 , 0.13875727571288787 , 15 );
createCube( 1.9549150281252625 ,  -0.5877852522924727 ,  15 );
drawLine( 3.572949016875157 , -1.7633557568774192 , 10 , 1.9549150281252625 , -0.5877852522924727 , 15 );
createCube( 1.954915028125262 ,  -2.938926261462365 ,  15 );
drawLine( 3.572949016875157 , -1.7633557568774192 , 10 , 1.954915028125262 , -2.938926261462365 , 15 );
createCube( 4.190983005625052 ,  -3.6654687894677265 ,  15 );
drawLine( 3.572949016875157 , -1.7633557568774192 , 10 , 4.190983005625052 , -3.6654687894677265 , 15 );
createCube( 8.927050983124841 ,  -2.853169548885461 ,  15 );
drawLine( 6.9270509831248415 , -2.853169548885461 , 10 , 8.927050983124841 , -2.853169548885461 , 15 );
createCube( 7.545084971874736 ,  -0.9510565162951539 ,  15 );
drawLine( 6.9270509831248415 , -2.853169548885461 , 10 , 7.545084971874736 , -0.9510565162951539 , 15 );
createCube( 5.309016994374947 ,  -1.6775990443005144 ,  15 );
drawLine( 6.9270509831248415 , -2.853169548885461 , 10 , 5.309016994374947 , -1.6775990443005144 , 15 );
createCube( 5.309016994374947 ,  -4.028740053470407 ,  15 );
drawLine( 6.9270509831248415 , -2.853169548885461 , 10 , 5.309016994374947 , -4.028740053470407 , 15 );
createCube( 7.545084971874736 ,  -4.755282581475768 ,  15 );
drawLine( 6.9270509831248415 , -2.853169548885461 , 10 , 7.545084971874736 , -4.755282581475768 , 15 );
createCube( 4.781152949374527 ,  8.559508646656381 ,  15 );
drawLine( 2.781152949374527 , 8.559508646656381 , 10 , 4.781152949374527 , 8.559508646656381 , 15 );
createCube( 1.4270509831248428 ,  7.46969485464834 ,  15 );
drawLine( -0.5729490168751572 , 7.46969485464834 , 10 , 1.4270509831248428 , 7.46969485464834 , 15 );
createCube( 1.427050983124842 ,  3.9429833408935018 ,  15 );
drawLine( -0.5729490168751581 , 3.9429833408935018 , 10 , 1.427050983124842 , 3.9429833408935018 , 15 );
createCube( 4.781152949374526 ,  2.85316954888546 ,  15 );
drawLine( 2.781152949374526 , 2.85316954888546 , 10 , 4.781152949374526 , 2.85316954888546 , 15 );
createCube( 0.14589803375031618 ,  3.5267115137548393 ,  15 );
drawLine( -1.8541019662496838 , 3.5267115137548393 , 10 , 0.14589803375031618 , 3.5267115137548393 , 15 );
createCube( -3.854101966249684 ,  3.5267115137548397 ,  15 );
drawLine( -1.8541019662496838 , 3.5267115137548393 , 10 , -3.854101966249684 , 3.5267115137548397 , 15 );
createCube( -1.9270509831248415 ,  6.379881062640299 ,  15 );
drawLine( -3.9270509831248415 , 6.379881062640299 , 10 , -1.9270509831248415 , 6.379881062640299 , 15 );
createCube( -3.3090169943749466 ,  8.281994095230607 ,  15 );
drawLine( -3.9270509831248415 , 6.379881062640299 , 10 , -3.3090169943749466 , 8.281994095230607 , 15 );
createCube( -5.545084971874736 ,  7.555451567225246 ,  15 );
drawLine( -3.9270509831248415 , 6.379881062640299 , 10 , -5.545084971874736 , 7.555451567225246 , 15 );
createCube( -5.545084971874736 ,  5.2043105580553535 ,  15 );
drawLine( -3.9270509831248415 , 6.379881062640299 , 10 , -5.545084971874736 , 5.2043105580553535 , 15 );
createCube( -3.309016994374947 ,  4.477768030049992 ,  15 );
drawLine( -3.9270509831248415 , 6.379881062640299 , 10 , -3.309016994374947 , 4.477768030049992 , 15 );
createCube( -5.281152949374526 ,  5.2900672706322585 ,  15 );
drawLine( -7.281152949374526 , 5.2900672706322585 , 10 , -5.281152949374526 , 5.2900672706322585 , 15 );
createCube( -7.281152949374526 ,  7.2900672706322585 ,  15 );
drawLine( -7.281152949374526 , 5.2900672706322585 , 10 , -7.281152949374526 , 7.2900672706322585 , 15 );
createCube( -9.281152949374526 ,  5.2900672706322585 ,  15 );
drawLine( -7.281152949374526 , 5.2900672706322585 , 10 , -9.281152949374526 , 5.2900672706322585 , 15 );
createCube( -7.281152949374526 ,  3.2900672706322585 ,  15 );
drawLine( -7.281152949374526 , 5.2900672706322585 , 10 , -7.281152949374526 , 3.2900672706322585 , 15 );
createCube( -5.281152949374526 ,  1.76335575687742 ,  15 );
drawLine( -7.281152949374526 , 1.76335575687742 , 10 , -5.281152949374526 , 1.76335575687742 , 15 );
createCube( -7.281152949374526 ,  3.76335575687742 ,  15 );
drawLine( -7.281152949374526 , 1.76335575687742 , 10 , -7.281152949374526 , 3.76335575687742 , 15 );
createCube( -9.281152949374526 ,  1.7633557568774203 ,  15 );
drawLine( -7.281152949374526 , 1.76335575687742 , 10 , -9.281152949374526 , 1.7633557568774203 , 15 );
createCube( -7.281152949374526 ,  -0.23664424312257992 ,  15 );
drawLine( -7.281152949374526 , 1.76335575687742 , 10 , -7.281152949374526 , -0.23664424312257992 , 15 );
createCube( -1.9270509831248424 ,  0.6735419648693783 ,  15 );
drawLine( -3.9270509831248424 , 0.6735419648693783 , 10 , -1.9270509831248424 , 0.6735419648693783 , 15 );
createCube( -3.3090169943749475 ,  2.5756549974596856 ,  15 );
drawLine( -3.9270509831248424 , 0.6735419648693783 , 10 , -3.3090169943749475 , 2.5756549974596856 , 15 );
createCube( -5.545084971874737 ,  1.8491124694543248 ,  15 );
drawLine( -3.9270509831248424 , 0.6735419648693783 , 10 , -5.545084971874737 , 1.8491124694543248 , 15 );
createCube( -5.545084971874737 ,  -0.5020285397155677 ,  15 );
drawLine( -3.9270509831248424 , 0.6735419648693783 , 10 , -5.545084971874737 , -0.5020285397155677 , 15 );
createCube( -3.309016994374948 ,  -1.228571067720929 ,  15 );
drawLine( -3.9270509831248424 , 0.6735419648693783 , 10 , -3.309016994374948 , -1.228571067720929 , 15 );
createCube( 0.1458980337503144 ,  -3.5267115137548384 ,  15 );
drawLine( -1.8541019662496856 , -3.5267115137548384 , 10 , 0.1458980337503144 , -3.5267115137548384 , 15 );
createCube( -2.854101966249685 ,  -1.794660706185961 ,  15 );
drawLine( -1.8541019662496856 , -3.5267115137548384 , 10 , -2.854101966249685 , -1.794660706185961 , 15 );
createCube( -2.8541019662496865 ,  -5.258762321323715 ,  15 );
drawLine( -1.8541019662496856 , -3.5267115137548384 , 10 , -2.8541019662496865 , -5.258762321323715 , 15 );
createCube( -1.9270509831248432 ,  -0.6735419648693779 ,  15 );
drawLine( -3.9270509831248432 , -0.6735419648693779 , 10 , -1.9270509831248432 , -0.6735419648693779 , 15 );
createCube( -5.281152949374528 ,  -1.7633557568774187 ,  15 );
drawLine( -7.281152949374528 , -1.7633557568774187 , 10 , -5.281152949374528 , -1.7633557568774187 , 15 );
createCube( -6.663118960624633 ,  0.13875727571288832 ,  15 );
drawLine( -7.281152949374528 , -1.7633557568774187 , 10 , -6.663118960624633 , 0.13875727571288832 , 15 );
createCube( -8.899186938124423 ,  -0.5877852522924722 ,  15 );
drawLine( -7.281152949374528 , -1.7633557568774187 , 10 , -8.899186938124423 , -0.5877852522924722 , 15 );
createCube( -8.899186938124423 ,  -2.938926261462365 ,  15 );
drawLine( -7.281152949374528 , -1.7633557568774187 , 10 , -8.899186938124423 , -2.938926261462365 , 15 );
createCube( -6.663118960624633 ,  -3.665468789467726 ,  15 );
drawLine( -7.281152949374528 , -1.7633557568774187 , 10 , -6.663118960624633 , -3.665468789467726 , 15 );
createCube( -5.281152949374528 ,  -5.290067270632258 ,  15 );
drawLine( -7.281152949374528 , -5.290067270632258 , 10 , -5.281152949374528 , -5.290067270632258 , 15 );
createCube( -8.281152949374528 ,  -3.55801646306338 ,  15 );
drawLine( -7.281152949374528 , -5.290067270632258 , 10 , -8.281152949374528 , -3.55801646306338 , 15 );
createCube( -8.28115294937453 ,  -7.022118078201134 ,  15 );
drawLine( -7.281152949374528 , -5.290067270632258 , 10 , -8.28115294937453 , -7.022118078201134 , 15 );
createCube( -1.9270509831248441 ,  -6.379881062640299 ,  15 );
drawLine( -3.927050983124844 , -6.379881062640299 , 10 , -1.9270509831248441 , -6.379881062640299 , 15 );
createCube( -5.927050983124844 ,  -6.379881062640299 ,  15 );
drawLine( -3.927050983124844 , -6.379881062640299 , 10 , -5.927050983124844 , -6.379881062640299 , 15 );
createCube( 6.854101966249683 ,  -5.706339097770922 ,  15 );
drawLine( 4.854101966249683 , -5.706339097770922 , 10 , 6.854101966249683 , -5.706339097770922 , 15 );
createCube( 3.8541019662496834 ,  -3.974288290202044 ,  15 );
drawLine( 4.854101966249683 , -5.706339097770922 , 10 , 3.8541019662496834 , -3.974288290202044 , 15 );
createCube( 3.854101966249682 ,  -7.438389905339799 ,  15 );
drawLine( 4.854101966249683 , -5.706339097770922 , 10 , 3.854101966249682 , -7.438389905339799 , 15 );
createCube( 4.781152949374526 ,  -2.8531695488854614 ,  15 );
drawLine( 2.7811529493745257 , -2.8531695488854614 , 10 , 4.781152949374526 , -2.8531695488854614 , 15 );
createCube( 1.7811529493745262 ,  -1.121118741316584 ,  15 );
drawLine( 2.7811529493745257 , -2.8531695488854614 , 10 , 1.7811529493745262 , -1.121118741316584 , 15 );
createCube( 1.7811529493745248 ,  -4.585220356454338 ,  15 );
drawLine( 2.7811529493745257 , -2.8531695488854614 , 10 , 1.7811529493745248 , -4.585220356454338 , 15 );
createCube( 1.4270509831248415 ,  -3.942983340893502 ,  15 );
drawLine( -0.5729490168751585 , -3.942983340893502 , 10 , 1.4270509831248415 , -3.942983340893502 , 15 );
createCube( -1.572949016875158 ,  -2.210932533324625 ,  15 );
drawLine( -0.5729490168751585 , -3.942983340893502 , 10 , -1.572949016875158 , -2.210932533324625 , 15 );
createCube( -1.5729490168751594 ,  -5.6750341484623785 ,  15 );
drawLine( -0.5729490168751585 , -3.942983340893502 , 10 , -1.5729490168751594 , -5.6750341484623785 , 15 );
createCube( 1.4270509831248406 ,  -7.469694854648341 ,  15 );
drawLine( -0.5729490168751594 , -7.469694854648341 , 10 , 1.4270509831248406 , -7.469694854648341 , 15 );

createCube( -4.045084971874736 ,  5.2043105580553535 ,  20 );
drawLine( -5.545084971874736 , 5.2043105580553535 , 15 , -4.045084971874736 , 5.2043105580553535 , 20 );
createCube( -1.8090169943749475 ,  2.5756549974596856 ,  20 );
drawLine( -3.3090169943749475 , 2.5756549974596856 , 15 , -1.8090169943749475 , 2.5756549974596856 , 20 );

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


  else if (key == GLUT_KEY_F1) //exit program
    exit(0);

  else if (key == GLUT_KEY_F2) //menu movement
     a -= 20;

  else if (key == GLUT_KEY_F3) //menu movement
     a += 20;


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
