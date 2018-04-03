#include <stdexcept>

inline
float&
DynamicBase::mass_get(void)
{
  return mass_;
}

inline
const float&
DynamicBase::mass_get() const
{
  return mass_;
}

inline
void
DynamicBase::mass_set(float mass)
{
  if (mass == 0)
    throw std::invalid_argument("Cannot set mass to 0");
  mass_ = mass;
}

inline
float&
DynamicBase::intr_friction_get()
{
  return intr_friction_;
}

inline
const float&
DynamicBase::intr_friction_get() const
{
  return intr_friction_;
}

inline
void
DynamicBase::intr_friction_set(float intr_friction)
{
  intr_friction_ = intr_friction;
}

inline
Vector&
DynamicBase::pos_get()
{
  return pos_;
}

inline
const Vector&
DynamicBase::pos_get() const
{
  return pos_;
}

inline
void
DynamicBase::pos_set(Vector pos)
{
  pos_ = pos;
}

inline
Vector& DynamicBase::vel_get()
{
  return vel_;
}

inline
const Vector&
DynamicBase::vel_get() const
{
  return vel_;
}

inline
void
DynamicBase::vel_set(Vector vel)
{
  vel_ = vel;
}

inline
Vector&
DynamicBase::acc_get()
{
  return acc_;
}

inline
const Vector&
DynamicBase::acc_get() const
{
  return acc_;
}

inline
void
DynamicBase::acc_set(Vector acc)
{
  acc_ = acc;
}

inline
Vector&
DynamicRotative::angularPos_get()
{
  return angularPos_;
}


inline
const Vector&
DynamicRotative::angularPos_get() const
{
  return angularPos_;
}

inline
Vector&
DynamicRotative::angularVel_get()
{
  return angularVel_;
}

inline
const Vector&
DynamicRotative::angularVel_get() const
{
  return angularVel_;
}

inline
Vector&
DynamicRotative::intrAngularFriction_get()
{
  return intrAngularFriction_;
}

inline
const Vector&
DynamicRotative::intrAngularFriction_get() const
{
  return intrAngularFriction_;
}

inline
Matrix&
DynamicRotative::inertia_get()
{
  return inertia_;
}

inline
const Matrix&
DynamicRotative::inertia_get() const
{
  return inertia_;
}

inline
Vector&
DynamicRotative::torque_get()
{
  return torque_;
}

inline
const Vector&
DynamicRotative::torque_get() const
{
  return torque_;
}
