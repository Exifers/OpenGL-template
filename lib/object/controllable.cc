#include <glutInterface/glutInterface.hh>

#include "controllable.hh"

Controllable::~Controllable()
{}

void
Controllable::update()
{
  DynamicRotative::update();
  dir_ = Vector();
  if (keyStates[KEY_UP])
    dir_ += groundDirection();
  if (keyStates[KEY_DOWN])
    dir_ += -groundDirection();
  if (keyStates[KEY_LEFT])
    dir_ += left();
  if (keyStates[KEY_RIGHT])
    dir_ += -left();
  if (keyStates[' '])
    dir_ += upwards();
  if (keyStates[KEY_SHIFT])
    dir_ += -upwards();
  force_set(dir_.normalized() / CONTROL_FORCE_FACTOR);
}
