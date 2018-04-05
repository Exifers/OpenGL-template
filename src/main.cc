#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <thread>

#include <keyboard/keyboard.hh>
#include <launcher/launcher.hh>
#include <glutInterface/glutInterface.hh>
#include <camera/camera.hh>
#include <primitive/primitive.hh>

void display(void)
{
  int matSpec[] = {1, 1, 1, 1};
  glMaterialiv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
  glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 100);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  Camera::instance().moveFrame();

  int lightPos[] = {0, -3, -3, 1};
  glLightiv(GL_LIGHT0, GL_POSITION, lightPos);

  Primitive::renderAll();

  /* Triggering motions here */
  glutSwapBuffers();
  glutPostRedisplay();

  KeyboardListener::applyKeyEventsOnAll();
  DynamicBase::updateAll();
}

int main(int argc, char **argv)
{
  auto s = Sphere(Vector(10, 0, 0), 1, 5, 50);
  auto s2 = Sphere(Vector(-10, 0, 0), 1, 5, 50);
  auto& launcher = Launcher::instance(argc, argv);
  launcher.launch();
  return 0;
}
