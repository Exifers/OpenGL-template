inline
float&
Dynamic::mass_get(void)
{
  return mass_;
}

inline
const float&
Dynamic::mass_get() const
{
  return mass_;
}

inline
void
Dynamic::mass_set(float mass)
{
  if (mass == 0)
    throw;
  mass_ = mass;
}

inline
float&
Dynamic::intr_friction_get()
{
  return intr_friction_;
}

inline
const float&
Dynamic::intr_friction_get() const
{
  return intr_friction_;
}

inline
void
Dynamic::intr_friction_set(float intr_friction)
{
  intr_friction_ = intr_friction;
}

inline
Vector&
Dynamic::pos_get()
{
  return pos_;
}

inline
const Vector&
Dynamic::pos_get() const
{
  return pos_;
}

inline
void
Dynamic::pos_set(Vector pos)
{
  pos_ = pos;
}

inline
Vector& Dynamic::vel_get()
{
  return vel_;
}

inline
const Vector&
Dynamic::vel_get() const
{
  return vel_;
}

inline
void
Dynamic::vel_set(Vector vel)
{
  vel_ = vel;
}

inline
Vector&
Dynamic::acc_get()
{
  return acc_;
}

inline
const Vector&
Dynamic::acc_get() const
{
  return acc_;
}

inline
void
Dynamic::acc_set(Vector acc)
{
  acc_ = acc;
}
