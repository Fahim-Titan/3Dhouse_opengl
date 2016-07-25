#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include <windows.h>  // for MS Windows

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
 
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
 
  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 
  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included
 
  //Multi-colored side - FRONT
  glBegin(GL_POLYGON);
 
  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  6.0, -4.0, -2.5 );      // P1 is red
  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  6.0,  2.0, -2.5 );      // P2 is green
  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -6.0,  2.0, -2.5 );      // P3 is blue
  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -6.0, -4.0, -2.5 );      // P4 is purple
 
  glEnd();
 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  6.0, -4.0, 2.5 );
  glVertex3f(  6.0,  2.0, 2.5 );
  glVertex3f( -6.0,  2.0, 2.5 );
  glVertex3f( -6.0, -4.0, 2.5 );
  glEnd();
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 6.0, -4.0, -2.5 );
  glVertex3f( 6.0,  2.0, -2.5 );
  glVertex3f( 6.0,  2.0,  2.5 );
  glVertex3f( 6.0, -4.0,  2.5 );
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -6.0, -4.0,  2.5 );
  glVertex3f( -6.0,  2.0,  2.5 );
  glVertex3f( -6.0,  2.0, -2.5 );
  glVertex3f( -6.0, -4.0, -2.5 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  6.0,  2.0,  2.5 );
  glVertex3f(  6.0,  2.0, -2.5 );
  glVertex3f( -6.0,  2.0, -2.5 );
  glVertex3f( -6.0,  2.0,  2.5 );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  6.0, -4.0, -2.5 );
  glVertex3f(  6.0, -4.0,  2.5 );
  glVertex3f( -6.0, -4.0,  2.5 );
  glVertex3f( -6.0, -4.0, -2.5 );
  glEnd();

  // chal front side
glBegin(GL_POLYGON);
  glColor3f(   0.78,  0.6, 0.4 );
  glVertex3f(  7.0,  2.0, 2.5 ); //1
  glVertex3f(  5.0,  4.0, 0.0 ); //2
  glVertex3f( -5.0,  4.0, 0.0 ); //3
  glVertex3f( -7.0,  2.0, 2.5 ); //4
  glEnd();

  // chal back side
glBegin(GL_POLYGON);
  glColor3f(   0.78,  0.69, 0.64 );
  glVertex3f(  7.0,  2.0, -2.5 ); //1
  glVertex3f(  5.0,  4.0, 0.0 ); //2
  glVertex3f( -5.0,  4.0, 0.0 ); //3
  glVertex3f( -7.0,  2.0, -2.5 ); //4
  glEnd();

  // chal right side
glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.29, 0.24 );
  glVertex3f(  7.0,  2.0, 2.5 ); //1
  glVertex3f(  7.0,  2.0, -2.5 ); //2
  glVertex3f(  5.0,  4.0, 0.0 ); //3
  //glVertex3f( -7.0,  2.0, -2.5 ); //4
  glEnd();

// chal right side
glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.29, 0.24 );
  glVertex3f( -7.0,  2.0, 2.5 ); //1
  glVertex3f( -7.0,  2.0, -2.5 ); //2
  glVertex3f( -5.0,  4.0, 0.0 ); //3
  //glVertex3f( -7.0,  2.0, -2.5 ); //4
  glEnd();
 
 
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
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(500, 500);
glutInitWindowPosition(200, 200);
  // Create window
  glutCreateWindow("3D House");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -5.0, 5.0);
  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);

 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
