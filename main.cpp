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

static int slices = 3;
static int stacks = 3;
double a = 90.0;

/* GLUT callback Handlers */

//funcion para hacer resize de la figura y de la ventana
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

//funcion donde se maneja la parte de las visualizaciones,
//tanto su posicion, como su movimiento de rotasion y traslacion
static void display(void)
{
    //const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    // glPushMatrix();
    //     glTranslated(0,0,-3);
    //     glRotated(-60,1,0,0); //rotacion del cono con la punta arriba girando
    //     glRotated(a,0,0,1);
    //     glutSolidCone(1,1,slices,stacks);
    // glPopMatrix();

    glPushMatrix();
        glTranslated(-3,0,-6);
        glRotated(-60,1,0,0); //rotacion del cono con la punta arriba girando
        glRotated(a,0,0,1);
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f( 1.0 ,  0.0 ,  1 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.30901699437494745 ,  0.9510565162951535 ,  1 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( -0.8090169943749473 ,  0.5877852522924732 ,  1 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( -0.8090169943749476 ,  -0.587785252292473 ,  1 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.30901699437494723 ,  -0.9510565162951536 ,  1 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 2.0 ,  0.0 ,  2 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 1.3090169943749475 ,  0.9510565162951535 ,  2 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( -0.6909830056250525 ,  0.9510565162951536 ,  2 );
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.19098300562505244 ,  -0.587785252292473 ,  2 );
    glPopMatrix();



    glutSwapBuffers();
}

//funcion que controla la rotación de las estructuras
//esta escuchando constantemente el teclado
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'p' :

            break;
        case 'q':
            exit(0);
            break;

        case '+':
            //slices++;
            //stacks++;
            a += 20;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                //slices--;
                //stacks--;
            }
            a -= 20;
            break;
        case 'd':
            //slices++;
            //stacks++;
            a += 20;
            break;

        case 'a':
            if (slices>3 && stacks>3)
            {
                //slices--;
                //stacks--;
            }
            a -= 20;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

//--------------------------ambient light-----------------------------
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
//----------------------end ambient light---------------------------
/* Program entry point */

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
