#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

bool *keyStates = new  bool[256];
float pos_x = 0;
float pos_y = 0;
float pos_z = 0;
float theta = 0;
float phi = 0;

void renderPrimitive(void)
{
  glutSolidSphere(1, 5, 5);
}

void display(void)
{
  int matSpec[] = {1, 1, 1, 1};
  glMaterialiv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
  glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 100);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(theta, 0, 0, 1);
  glRotatef(phi, 0, 1, 0);
  glTranslatef(pos_x, pos_y, -10 + pos_z);

  int lightPos[] = {0, -3, -3, 1};
  glLightiv(GL_LIGHT0, GL_POSITION, lightPos);

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

void initGL()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
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
  switch( (int) key)
  {
    case 'z':
      pos_y += 0.1;
      break;
    case 's':
      pos_y -= 0.1;
      break;
    case 'd':
      pos_x += 0.1;
      break;
    case 'q':
      pos_x -= 0.1;
      break;
    case 'a':
      pos_z += 0.1;
      break;
    case 'e':
      pos_z -= 0.1;
      break;
    case 'o':
      theta += 2;
      break;
    case 'p':
      theta -= 2;
      break;
    case 'l':
      phi += 2;
      break;
    case 'm':
      phi -= 2;
      break;
  }
}

int main(int argc, char **argv)
{
  /* Creating a window */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Glew test");

  /* Binding basic functions */
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyPressed);
  glutKeyboardUpFunc(keyUp);
  initGL();

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
