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

Primitive::Primitive(Vector pos, Vector rot)
  : pos_(pos), rot_(rot)
{
  instances_.push_back(this);
}

Primitive::Primitive(Vector pos)
  : pos_(pos), rot_(Vector())
{
  instances_.push_back(this);
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
  glRotatef(rot_[0], 1, 0, 0);
  glRotatef(rot_[1], 0, 1, 0);
  glRotatef(rot_[2], 0, 0, 1);
}

void
Primitive::resetFrame()
{
  glTranslatef(-pos_[0], -pos_[1], -pos_[2]);
  glRotatef(-rot_[0], 1, 0, 0);
  glRotatef(-rot_[1], 0, 1, 0);
  glRotatef(-rot_[2], 0, 0, 1);
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
