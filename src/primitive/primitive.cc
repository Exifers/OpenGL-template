#include <GL/glew.h>
#include <GL/glut.h>

#include "primitive.hh"

/*-------------
  | Primitive |
  -------------*/

std::list<Primitive *> Primitive::instances_;

Primitive::Primitive()
{
  instances_.push_back(this);
}

Primitive::~Primitive()
{
  instances_.remove(this);
}

Primitive::Primitive(Vector pos, Vector angularPos)
{
  pos_ = pos;
  angularPos_ = angularPos;
  instances_.push_back(this);
}

Primitive::Primitive(Vector pos)
{
  pos_ = pos;
  instances_.push_back(this);
}

void
Primitive::update()
{
  DynamicRotative::update();
  Takable::update();
}

  void
Primitive::renderAll()
{
  for (auto it = instances_.begin(); it != instances_.end(); it++)
  {
    (*it)->render();
  }
}

  void
Primitive::moveFrame()
{
  glTranslatef(pos_[0], pos_[1], pos_[2]);
  glRotatef(angularPos_[0], 1, 0, 0);
  glRotatef(angularPos_[1], 0, 1, 0);
  glRotatef(angularPos_[2], 0, 0, 1);
}

  void
Primitive::resetFrame()
{
  glTranslatef(-pos_[0], -pos_[1], -pos_[2]);
  glRotatef(-angularPos_[0], 1, 0, 0);
  glRotatef(-angularPos_[1], 0, 1, 0);
  glRotatef(-angularPos_[2], 0, 0, 1);
}

  void
Primitive::render()
{
  moveFrame();
  renderingWrapper();
  resetFrame();
}

/*----------
  | Sphere |
  ----------*/

Sphere::Sphere(Vector pos, Vector rot, float r)
  : Primitive(pos, rot), r_(r)
{}

Sphere::Sphere(Vector pos, float r, int slices, int stacks)
  : Primitive(pos), r_(r), slices_(slices), stacks_(stacks)
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
  : Primitive(pos), c_(c)
{}

Cube::Cube(Vector pos, Vector rot, float c)
  : Primitive(pos, rot), c_(c)
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
  {
    taken_get() = true;
  }
  Takable::mousePressed(button, x, y);
}

void
Cube::mouseReleased(int button, int x, int y)
{
  if (button == MOUSE_BUTTON_LEFT)
  {
    taken_get() = false;
  }
  Takable::mouseReleased(button, x, y);
}

void
Cube::mouseMoved(int x, int y)
{
  Takable::mouseMoved(x, y);
}
