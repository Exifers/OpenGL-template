#include <math.h>
#include <math/utils.hh>

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

Vector
DynamicRotative::direction() const
{
  return groundDirection() * cos(toRadians(angularPos_[0]))
       - upwards()         * sin(toRadians(angularPos_[0]));
}

Vector
DynamicRotative::groundDirection() const
{
  return groundDirectionNormalized() * cos(toRadians(angularPos_[0]));
}

Vector
DynamicRotative::groundDirectionNormalized() const
{
  return Vector(0, 0, 1) * cos(toRadians(angularPos_[1]))
       - Vector(1, 0, 0) * sin(toRadians(angularPos_[1]));
}

Vector
DynamicRotative::upwards() const
{
  return Vector(0, -1, 0);
}

DynamicRotative::~DynamicRotative()
{}

void
Controllable::keyPressed(int key)
{
  key = key;
}

void
Controllable::keyReleased(int key)
{
  key = key;
}

void
Controllable::update()
{
  DynamicRotative::update();
  dir_ = Vector();
  if (keyStates[KEY_UP])
    dir_ += (groundDirection() / 5);
  if (keyStates[KEY_DOWN])
    dir_ += (-groundDirection() / 5);
  if (keyStates[KEY_LEFT])
    dir_ += ((direction().cross(upwards())).normalized() / 5);
  if (keyStates[KEY_RIGHT])
    dir_ += ((-direction().cross(upwards())).normalized() / 5);
  if (keyStates[' '])
    dir_ += (upwards() / 5);
  if (keyStates[KEY_SHIFT])
    dir_ += (-upwards() / 5);
  apply_force(dir_.normalized() / 5);
}

Controllable::~Controllable()
{}
