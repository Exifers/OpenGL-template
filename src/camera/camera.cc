#include <iostream>

#include <GL/glew.h>

#include "camera.hh"

Camera
Camera::instance()
{
  static Camera instance;
  return instance;
}

void
Camera::update()
{
  Controllable::update();
}

void
Camera::moveFrame() const
{
  glTranslatef(pos_[0], pos_[1], pos_[2]);
}

std::ostream&
operator<<(std::ostream& ostr, Camera c)
{
  ostr << "[" << c.pos_[0] << ", " << c.pos_[1] << ", " << c.pos_[2]
    << "; " << c.angularPos_[0] << ", " << c.angularPos_[1] << ", "
    << c.angularPos_[2] << "]";
  return ostr;
}
