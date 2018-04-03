#include <iostream>

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
  std::cout << *this << std::endl;
}

std::ostream&
operator<<(std::ostream& ostr, Camera c)
{
  ostr << "[" << c.pos_[0] << ", " << c.pos_[1] << ", " << c.pos_[2]
    << "; " << c.angularPos_[0] << ", " << c.angularPos_[1] << ", "
    << c.angularPos_[2] << "]";
  return ostr;
}
