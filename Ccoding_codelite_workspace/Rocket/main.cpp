// gcc glut.cpp -o glut -lglut -lGL

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

float a = -1.0f, b = 0.5f, c = 0.5f, d = -0.5f;
int t = 0;
float blue = 1.0f;

void display()
   {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, blue);
	//glRectf(a,b,c,d);
	glutWireSphere(.5, 10, 10);
	glutSwapBuffers();
   }


void func(void) {
  blue -= 0.001f;
  if (blue < 0.0f) blue = 1.0f;
  a += 0.001f; if (a > 0.0f) a = -1.0f;
  display();
}
 
void setup() {   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); }

int main(int argc, char *argv[])
  {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
     glutInitWindowSize(800,600);
     glutCreateWindow("Hello World");

     setup();
     glutDisplayFunc(display);

    glutIdleFunc(func);

     glutMainLoop();
     return 0;
  }