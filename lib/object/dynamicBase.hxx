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
float&
DynamicBase::friction_get()
{
  return friction_;
}

inline
const float&
DynamicBase::friction_get() const
{
  return friction_;
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
