#include "dynamicRotative.hh"

DynamicRotative::~DynamicRotative()
{}

void DynamicRotative::update()
{
  DynamicBase::update();
  angularVel_ *= angularFriction_;
  angularVel_ += inertia_.invert() * torque_;
  angularPos_ += angularVel_;
}

std::ostream& operator<<(std::ostream& ostr, DynamicRotative& d)
{
  ostr << "{ " << d.pos_ << " ; " << d.angularPos_ << " | "
               << d.vel_ << " ; " << d.angularVel_ << " }" << std::endl;
  return ostr;
}
