#include <GL/glew.h>
#include <GL/glut.h>

#include "light.hh"

Light::Light(Vector pos, Vector angularPos)
  : Renderable(pos, angularPos)
{}

void
Light::renderingWrapper()
{
  int lightPos[] = {0, 0, 0, 1};
  glLightiv(GL_LIGHT0, GL_POSITION, lightPos);
}
