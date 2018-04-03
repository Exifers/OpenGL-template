#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <thread>

#include <keyboard/keyboard.hh>
#include <launcher/launcher.hh>
#include <glutInterface/glutInterface.hh>
#include <camera/camera.hh>

float pos_x = 0;
float pos_y = 0;
float pos_z = 0;
float theta = 0;
float phi = 0;

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
  glutSolidSphere(1, 5, 5);
  glFlush();

  /* Triggering motions here */
  glutSwapBuffers();
  glutPostRedisplay();

  DynamicBase::updateAll();
  KeyboardListener::applyKeyEventsOnAll();
}

int main(int argc, char **argv)
{
  Camera::instance();
  auto& launcher = Launcher::instance(argc, argv);
  launcher.launch();
  return 0;
}
