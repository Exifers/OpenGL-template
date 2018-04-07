#pragma once

#include <cmath>

#include <math/vector.hh>

class StaticBase
{
  public:
    virtual ~StaticBase() = 0;

    Vector direction() const;
    Vector groundDirection() const;
    Vector groundDirectionNormalized() const;
    Vector left() const;
    Vector upwards() const;

    Vector& pos_get();
    const Vector& pos_get() const;

    Vector& angularPos_get();
    const Vector& angularPos_get() const;
  protected:
    Vector pos_ = Vector();
    Vector angularPos_ = Vector();
};

#include "staticBase.hxx"
