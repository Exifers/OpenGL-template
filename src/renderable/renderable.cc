#include <GL/glew.h>
#include <GL/glut.h>

#include "renderable.hh"

std::list<Renderable *> Renderable::instances_;

Renderable::Renderable()
{
  instances_.push_back(this);
}

Renderable::~Renderable()
{
  instances_.remove(this);
}

Renderable::Renderable(Vector pos, Vector angularPos)
{
  pos_ = pos;
  angularPos_ = angularPos;
  instances_.push_back(this);
}

Renderable::Renderable(Vector pos)
{
  pos_ = pos;
  instances_.push_back(this);
}

void
Renderable::update()
{
  DynamicRotative::update();
  Takable::update();
}

void
Renderable::renderAll()
{
  for (auto it = instances_.begin(); it != instances_.end(); it++)
    (*it)->render();
}

void
Renderable::moveFrame()
{
  glTranslatef(pos_[0], pos_[1], pos_[2]);
  glRotatef(angularPos_[0], 1, 0, 0);
  glRotatef(angularPos_[1], 0, 1, 0);
  glRotatef(angularPos_[2], 0, 0, 1);
}

void
Renderable::resetFrame()
{
  glRotatef(-angularPos_[0], 1, 0, 0);
  glRotatef(-angularPos_[1], 0, 1, 0);
  glRotatef(-angularPos_[2], 0, 0, 1);
  glTranslatef(-pos_[0], -pos_[1], -pos_[2]);
}

void
Renderable::render()
{
  moveFrame();
  renderingWrapper();
  resetFrame();
}
