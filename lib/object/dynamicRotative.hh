#pragma once

#include <ostream>

#include <math/vector.hh>
#include <math/matrix.hh>

#include "dynamicBase.hh"

class DynamicRotative : public virtual DynamicBase
{
  public:
    virtual ~DynamicRotative() = 0;

    virtual void update() override;

    Vector& angularVel_get();
    const Vector& angularVel_get() const;

    Vector& angularFriction_get();
    const Vector& angularFriction_get() const;

    Matrix& inertia_get();
    const Matrix& inertia_get() const;

    Vector& torque_get();
    const Vector& torque_get() const;

    friend std::ostream& operator<<(std::ostream& ostr, DynamicRotative& d);

  protected:
    Vector angularVel_ = Vector();
    Vector angularFriction_ = Vector(1, 1, 1);
    Matrix inertia_ = Matrix::identity();
    Vector torque_ = Vector();
};

#include "dynamicRotative.hxx"
