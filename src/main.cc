#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

bool *keyStates = new  bool[256];
float t = 0;

void renderPrimitive(void)
{
  glColor3f(0.0f, 0.0f, 1.0f);
  glBegin(GL_QUADS);
  glVertex3f(-1.0f, -1.0f, 0.0f);
  glVertex3f(-1.0f,  1.0f, 0.0f);
  glVertex3f( 1.0f,  1.0f, 0.0f);
  glVertex3f( 1.0f, -1.0f, 0.0f);
  glEnd();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -10.0f - t);
  t += 0.001;

  /* Drawing */
  renderPrimitive();
  glFlush();

  /* Triggering motions here */
  glutSwapBuffers();
  glutPostRedisplay();
}

/** Reshape is called once at openGL launching, sets up settings about 3D
**  rendering. */
void reshape(int width, int height)
{
  /* Setting up the local frame of the viewport rectange */
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
}

void keyUp (unsigned char key, int x, int y)
{
  keyStates[key] = false;
  x = x;
  y = y;
}

void keyPressed(unsigned char key, int x, int y)
{
  keyStates[key] = true;
  x = x;
  y = y;
}

int main(int argc, char **argv)
{
  /* Creating a window */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Glew test");

  /* Binding basic functions */
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyPressed);
  glutKeyboardUpFunc(keyUp);

  /* Checking for errors */
  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    std::cerr << "glewInit failed : " << glewGetErrorString(err) << std::endl;
  }
  std::cout << "Glew initialized using " << glewGetString(GLEW_VERSION)
    << std::endl;

  /* Running the window */
  glutMainLoop();
  return 0;
}
