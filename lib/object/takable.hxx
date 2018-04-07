inline
Controllable *&
Takable::taker_get()
{
  return taker_;
}

inline
Controllable * const &
Takable::taker_get() const
{
  return taker_;
}

inline
bool&
Takable::taken_get()
{
  return taken_;
}

inline
const bool&
Takable::taken_get() const
{
  return taken_;
}
