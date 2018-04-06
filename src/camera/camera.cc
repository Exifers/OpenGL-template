#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include "camera.hh"

int gWidth  = 0;
int gHeight = 0;

Camera&
Camera::instance()
{
  static Camera instance;
  return instance;
}

void
Camera::update()
{
  Controllable::update();

  int width = glutGet(GLUT_WINDOW_WIDTH);
  int height = glutGet(GLUT_WINDOW_HEIGHT);
  if (cursorHasInitValue())
    setCursorOnMiddle();
  if (gWidth == width && gHeight == height)
    orientate(mousePos.first, mousePos.second, width, height);
  else
  {
    setCursorOnMiddle();
    gWidth = width;
    gHeight = height;
  }
  if (cursorOnSide())
  {
    bufferAngle_ += localAngle_;
    localAngle_ = 0;
    centerCursor();
  }
}

bool
Camera::cursorOnSide()
{
  int width = glutGet(GLUT_WINDOW_WIDTH);
  return mousePos.first <= 0 || mousePos.second >= width - 1;
}

bool
Camera::cursorHasInitValue()
{
  return mousePos.first == -1 || mousePos.second == -1;
}

void
Camera::setCursorOnMiddle()
{
  int newX = glutGet(GLUT_WINDOW_WIDTH)/2;
  int newY = glutGet(GLUT_WINDOW_HEIGHT)/2;
  MouseMovedQueue::wrapping = true;
  glutWarpPointer(newX, newY);
  mousePos.first = newX;
  mousePos.second = newY;
}

void
Camera::centerCursor()
{
  int newX = glutGet(GLUT_WINDOW_WIDTH)/2;
  int newY = mousePos.second;
  MouseMovedQueue::wrapping = true;
  glutWarpPointer(newX, newY);
  mousePos.first = newX;
  mousePos.second = newY;
}

void
Camera::moveFrame() const
{
  glRotatef(angularPos_[0], 1, 0, 0);
  glRotatef(angularPos_[1], 0, 1, 0);
  glRotatef(angularPos_[2], 0, 0, 1);
  glTranslatef(pos_[0], pos_[1], pos_[2]);
}

void
Camera::orientate(int x, int y, int width, int height)
{
  float hw = ((float) width) / 2;
  float hh = ((float) height) / 2;
  float rx = (x - hw) / hw;
  float ry = (y - hh) / hh;
  localAngle_ = rx * HALF_ANGLE;
  angularPos_[1] = bufferAngle_ + localAngle_;
  angularPos_[0] = ry * QUARTER_ANGLE;
}


float&
Camera::bufferAngle_get()
{
  return bufferAngle_;
}

const float&
Camera::bufferAngle_get() const
{
  return bufferAngle_;
}

std::ostream&
operator<<(std::ostream& ostr, Camera c)
{
  ostr << "[" << c.pos_[0] << ", " << c.pos_[1] << ", " << c.pos_[2]
    << "; " << c.angularPos_[0] << ", " << c.angularPos_[1] << ", "
    << c.angularPos_[2] << "]";
  return ostr;
}
