#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <thread>

#include <keyboard/keyboard.hh>
#include <launcher/launcher.hh>
#include <glutInterface/glutInterface.hh>
#include <camera/camera.hh>
#include <renderable/primitive.hh>
#include <renderable/light.hh>
#include <renderable/mountains.hh>
#include <mouse/mouse.hh>
#include <math/utils.hh>

void display(void)
{
  int matSpec[] = {1, 1, 1, 1};
  glMaterialiv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
  glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 100);

  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Applying last events
  KeyboardListener::applyKeyEventsOnAll();
  MouseListener::applyMouseEventOnAll();

  // Updating and rendering
  // Note: movements are more fluid when stuff are performed in this order:
  Camera::instance().moveFrame();
  DynamicBase::updateAll();
  Renderable::renderAll();

  // Triggering motions here
  glutSwapBuffers();
  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  auto p = Plane();
  p.dimension_get() = Vector(100, 0, 100);
  p.side_get() = Vector(0, 0, 20);
  p.pos_get() += Vector(20, 0, 0);

  auto c = Cube();
  c.pos_get() += Vector(10, 0, 0);

  Camera::instance().pos_get() = Vector(0, 0, 5);

  c.taker_get() = &Camera::instance();

  auto& launcher = Launcher::instance(argc, argv);
  launcher.launch();
  return 0;
}
