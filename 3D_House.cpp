#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
 
#include "imageloader.h"

using namespace std;


GLuint _textureId;
GLuint _rooftextureId;
GLuint _doortextureId;
GLuint _windowtextureId;

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

glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 
  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included
 glPushMatrix();
  //Multi-colored side - FRONT
  glBegin(GL_POLYGON);
 
//  glColor3f( 1.0, 0.0, 0.0 );
     glTexCoord2f(0.0, 0.0);	glVertex3f(  6.0, -4.0, -2.5 );      // P1 is red
//  glColor3f( 0.0, 1.0, 0.0 );
   glTexCoord2f(0.0, 3.0);	glVertex3f(  6.0,  2.0, -2.5 );      // P2 is green
//  glColor3f( 0.0, 0.0, 1.0 );     
glTexCoord2f(3.0, 3.0);	glVertex3f( -6.0,  2.0, -2.5 );      // P3 is blue
//  glColor3f( 1.0, 0.0, 1.0 );
     glTexCoord2f(3.0, 0.0);	glVertex3f( -6.0, -4.0, -2.5 );      // P4 is purple
 
  glEnd();
 
  // White side - BACK
  glBegin(GL_POLYGON);
  //glColor3f(   1.0,  1.0, 1.0 );
glTexCoord2f(0.0, 0.0);
  glVertex3f(  6.0, -4.0, 2.5 );
glTexCoord2f(0.0, 3.0);
  glVertex3f(  6.0,  2.0, 2.5 );
glTexCoord2f(3.0, 3.0);
  glVertex3f( -6.0,  2.0, 2.5 );
glTexCoord2f(3.0, 0.0);
  glVertex3f( -6.0, -4.0, 2.5 );
  glEnd();
 

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  //glColor3f(  1.0,  0.0,  1.0 );
  glTexCoord2f(0.0, 0.0);		glVertex3f( 6.0, -4.0, -2.5 );
 glTexCoord2f(0.0, 3.0);		glVertex3f( 6.0,  2.0, -2.5 );
glTexCoord2f(3.0, 3.0);			glVertex3f( 6.0,  2.0,  2.5 );
  glTexCoord2f(3.0, 0.0);		glVertex3f( 6.0, -4.0,  2.5 );
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  1.0,  0.0 );
  glTexCoord2f(0.0, 0.0);		glVertex3f( -6.0, -4.0,  2.5 );
  glTexCoord2f(0.0, 3.0);		glVertex3f( -6.0,  2.0,  2.5 );
  glTexCoord2f(3.0, 3.0);		glVertex3f( -6.0,  2.0, -2.5 );
  glTexCoord2f(3.0, 0.0);		glVertex3f( -6.0, -4.0, -2.5 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );
  glTexCoord2f(0.0, 0.0);		glVertex3f(  6.0,  2.0,  2.5 );
  glTexCoord2f(0.0, 3.0);		glVertex3f(  6.0,  2.0, -2.5 );
  glTexCoord2f(3.0, 3.0);		glVertex3f( -6.0,  2.0, -2.5 );
  glTexCoord2f(3.0, 0.0);		glVertex3f( -6.0,  2.0,  2.5 );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  //glColor3f(   1.0,  0.0,  0.0 );
  glTexCoord2f(0.0, 0.0);		glVertex3f(  6.0, -4.0, -2.5 );
  glTexCoord2f(0.0, 3.0);		glVertex3f(  6.0, -4.0,  2.5 );
  glTexCoord2f(3.0, 3.0);		glVertex3f( -6.0, -4.0,  2.5 );
  glTexCoord2f(3.0, 0.0);		glVertex3f( -6.0, -4.0, -2.5 );
  glEnd();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _rooftextureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



  // chal front side
glBegin(GL_POLYGON);
  //glColor3f(   0.78,  0.6, 0.4 );
  glTexCoord2f(0.0, 0.0);		glVertex3f(  7.0,  2.0, 2.5 ); //1
  glTexCoord2f(0.0, 3.0);		glVertex3f(  5.0,  4.0, 0.0 ); //2
  glTexCoord2f(3.0, 3.0);		glVertex3f( -5.0,  4.0, 0.0 ); //3
  glTexCoord2f(3.0, 0.0);		glVertex3f( -7.0,  2.0, 2.5 ); //4
  glEnd();

  // chal back side
glBegin(GL_POLYGON);
  //glColor3f(   0.78,  0.69, 0.64 );
  glTexCoord2f(0.0, 0.0);		glVertex3f(  7.0,  2.0, -2.5 ); //1
  glTexCoord2f(0.0, 3.0);		glVertex3f(  5.0,  4.0, 0.0 ); //2
  glTexCoord2f(3.0, 3.0);		glVertex3f( -5.0,  4.0, 0.0 ); //3
  glTexCoord2f(3.0, 0.0);		glVertex3f( -7.0,  2.0, -2.5 ); //4
  glEnd();

  // chal right side
glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.29, 0.24 );
  glTexCoord2f(0.0, 0.0);		glVertex3f(  7.0,  2.0, 2.5 ); //1
  glTexCoord2f(0.0, 3.0);		glVertex3f(  7.0,  2.0, -2.5 ); //2
  glTexCoord2f(3.0, 0.0);		glVertex3f(  5.0,  4.0, 0.0 ); //3
  //glVertex3f( -7.0,  2.0, -2.5 ); //4
  glEnd();

// chal right side
glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.29, 0.24 );
  glTexCoord2f(0.0, 0.0);		glVertex3f( -7.0,  2.0, 2.5 ); //1
  glTexCoord2f(0.0, 3.0);		glVertex3f( -7.0,  2.0, -2.5 ); //2
  glTexCoord2f(3.0, 0.0);		glVertex3f( -5.0,  4.0, 0.0 ); //3
  //glVertex3f( -7.0,  2.0, -2.5 ); //4
  glEnd();
 glPopMatrix();




	glBindTexture(GL_TEXTURE_2D, _doortextureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


//door
  glBegin(GL_POLYGON);
  //glColor3f(   1.0,  1.0, 1.0 );
glTexCoord2f(0.0, 0.0);
  glVertex3f(  2.0, -4.0, 2.6 );
glTexCoord2f(0.0, 1.0);
  glVertex3f(  2.0,  0.0, 2.6 );
glTexCoord2f(1.0, 1.0);
  glVertex3f( -2.0,  0.0, 2.6 );
glTexCoord2f(1.0, 0.0);
  glVertex3f( -2.0, -4.0, 2.6 );
  glEnd();



glBindTexture(GL_TEXTURE_2D, _windowtextureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//window front side
  glBegin(GL_POLYGON);
  //glColor3f(   1.0,  1.0, 1.0 );
glTexCoord2f(0.0, 0.0);
  glVertex3f(  4.9, -2.0, 2.6 );
glTexCoord2f(0.0, 1.0);
  glVertex3f(  4.9, -1.0, 2.6 );
glTexCoord2f(1.0, 1.0);
  glVertex3f( 3.5,  -1.0, 2.6 );
glTexCoord2f(1.0, 0.0);
  glVertex3f( 3.5, -2.0, 2.6 );
  glEnd();

//window right side
  glBegin(GL_POLYGON);
  //glColor3f(   1.0,  1.0, 1.0 );
glTexCoord2f(0.0, 0.0);
  glVertex3f( 6.1, -2.5, -1.6 );
glTexCoord2f(0.0, 1.0);
  glVertex3f(  6.1, 0.0, -1.6 );
glTexCoord2f(1.0, 1.0);
  glVertex3f( 6.1,  0.0, 1.6 );
glTexCoord2f(1.0, 0.0);
  glVertex3f( 6.1, -2.5, 1.6 );
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
 

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}



void initialize() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 200.0);
	Image* image = loadBMP("bricks.bmp");
	Image* img = loadBMP("roof.bmp");
	Image* door = loadBMP("door.bmp");
	Image* window = loadBMP("window.bmp");

	_textureId = loadTexture(image);
	_rooftextureId = loadTexture(img);
	_doortextureId = loadTexture(door);
	_windowtextureId = loadTexture(window);

	delete image;
	delete img; 
	delete door;
	delete window;
}



void lightSetting()
{

	GLfloat ambientIntensity[4] = {0.6, 0.6, 0.6, 1.0};

	GLfloat position[4] = {1.0, -1.0, 0.0, 0.0};

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientIntensity);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
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
initialize();
	lightSetting();
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 }
