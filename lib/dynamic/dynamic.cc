#include "dynamic.hh"

std::list<DynamicBase *> DynamicBase::instances_;

DynamicBase::DynamicBase()
{
  instances_.push_back(this);
}

DynamicBase::~DynamicBase()
{
  instances_.remove(this);
}

void DynamicBase::update() {
  vel_ *= intr_friction_;
  vel_ += acc_;
  pos_ += vel_;
}

void DynamicBase::apply_force(Vector force) {
  acc_ = force / mass_;
}

void DynamicBase::updateAll()
{
  for (auto it = instances_.begin(); it != instances_.end(); it++)
  {
    (*it)->update();
  }
}

void DynamicRotative::update()
{
  DynamicBase::update();
  angularVel_ *= intrAngularFriction_;
  auto dd = inertia_.invert() * torque_;
  angularVel_ += inertia_.invert() * torque_;
  angularPos_ += angularVel_;
}

DynamicRotative::~DynamicRotative()
{}

void
Controllable::keyPressed(int key)
{
  switch(key)
  {
    case KEY_UP:
      dir_ += Vector(0, 0, 1);
      break;
    case KEY_DOWN:
      dir_ += Vector(0, 0, -1);
      break;
    case KEY_LEFT:
      dir_ += Vector(1, 0, 0);
      break;
    case KEY_RIGHT:
      dir_ += Vector(-1, 0, 0);
      break;
    case ' ':
      dir_ += Vector(0, -1, 0);
      break;
    case KEY_SHIFT:
      dir_ += Vector(0, 1, 0);
      break;
  }
  apply_force(dir_.normalized() / 5);
}

void
Controllable::keyReleased(int key)
{
  switch(key)
  {
    case KEY_UP:
      dir_ -= Vector(0, 0, 1);
      break;
    case KEY_DOWN:
      dir_ -= Vector(0, 0, -1);
      break;
    case KEY_LEFT:
      dir_ -= Vector(1, 0, 0);
      break;
    case KEY_RIGHT:
      dir_ -= Vector(-1, 0, 0);
      break;
    case ' ':
      dir_ -= Vector(0, -1, 0);
      break;
    case KEY_SHIFT:
      dir_ -= Vector(0, 1, 0);
      break;
  }
  apply_force(dir_.normalized() / 5);
}

Controllable::~Controllable()
{}
