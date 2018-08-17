#include <GL/glew.h>
#include <GL/glut.h>

#include "primitive.hh"

/*----------
  | Sphere |
  ----------*/

Sphere::Sphere(Vector pos, Vector rot, float r)
  : Renderable(pos, rot), r_(r)
{}

Sphere::Sphere(Vector pos, float r, int slices, int stacks)
  : Renderable(pos), r_(r), slices_(slices), stacks_(stacks)
{}

void
Sphere::renderingWrapper()
{
  glutSolidSphere(r_, slices_, stacks_);
  glFlush();
}

/*--------
  | Cube |
  --------*/

Cube::Cube(Vector pos, float c)
  : Renderable(pos), c_(c)
{}

Cube::Cube(Vector pos, Vector rot, float c)
  : Renderable(pos, rot), c_(c)
{}

Cube::Cube(float c)
  : c_(c)
{}

void
Cube::renderingWrapper()
{
  glBegin(GL_QUADS);
  glVertex3f(c_,c_,c_);
  glVertex3f(c_,-c_,c_);
  glVertex3f(-c_,-c_,c_);
  glVertex3f(-c_,c_,c_);

  glVertex3f(c_,c_,-c_);
  glVertex3f(c_,-c_,-c_);
  glVertex3f(-c_,-c_,-c_);
  glVertex3f(-c_,c_,-c_);

  glVertex3f(c_,c_,c_);
  glVertex3f(c_,-c_,c_);
  glVertex3f(c_,-c_,-c_);
  glVertex3f(c_,c_,-c_);

  glVertex3f(-c_,c_,c_);
  glVertex3f(-c_,-c_,c_);
  glVertex3f(-c_,-c_,-c_);
  glVertex3f(-c_,c_,-c_);

  glVertex3f(-c_,c_,-c_);
  glVertex3f(-c_,c_,c_);
  glVertex3f(c_,c_,c_);
  glVertex3f(c_,c_,-c_);

  glVertex3f(-c_,-c_,-c_);
  glVertex3f(-c_,-c_,c_);
  glVertex3f(c_,-c_,c_);
  glVertex3f(c_,-c_,-c_);
  glEnd();
}

void
Cube::mousePressed(int button, int x, int y)
{
  if (button == MOUSE_BUTTON_LEFT)
    taken_get() = true;
  Takable::mousePressed(button, x, y);
}

void
Cube::mouseReleased(int button, int x, int y)
{
  if (button == MOUSE_BUTTON_LEFT)
    taken_get() = false;
  Takable::mouseReleased(button, x, y);
}

void
Cube::mouseMoved(int x, int y)
{
  Takable::mouseMoved(x, y);
}

/*---------
  | Plane |
  ---------*/

void
Plane::renderingWrapper()
{
  if (dimension_.cross(side_).size() == 0)
    return;

  glBegin(GL_QUADS);

  glVertex3f(0, 0, 0);
  auto v = dimension_ - side_;
  glVertex3f(v.x_get(), v.y_get(), v.z_get());
  glVertex3f(dimension_.x_get(), dimension_.y_get(), dimension_.z_get());
  glVertex3f(side_.x_get(), side_.y_get(), side_.z_get());

  glEnd();
}

Vector&
Plane::dimension_get()
{
  return dimension_;
}

const Vector&
Plane::dimension_get() const
{
  return dimension_;
}

Vector&
Plane::side_get()
{
  return side_;
}

const Vector&
Plane::side_get() const
{
  return side_;
}
