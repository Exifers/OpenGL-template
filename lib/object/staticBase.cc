#include <math/utils.hh>

#include "staticBase.hh"

StaticBase::~StaticBase()
{}

Vector
StaticBase::direction() const
{
  return groundDirection() * cos(toRadians(angularPos_.x_get()))
       + upwards()         * sin(toRadians(angularPos_.x_get()));
}

Vector
StaticBase::groundDirection() const
{
  return groundDirectionNormalized() * cos(toRadians(angularPos_.x_get()));
}

Vector
StaticBase::groundDirectionNormalized() const
{
  return Vector(1, 0, 0) * sin(toRadians(angularPos_.y_get()))
       - Vector(0, 0, 1) * cos(toRadians(angularPos_.y_get()));
}

Vector
StaticBase::upwards() const
{
  return Vector(0, 1, 0);
}

Vector
StaticBase::left() const
{
  return (upwards().cross(groundDirection())).normalized();
}
