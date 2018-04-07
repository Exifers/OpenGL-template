#pragma once

#include <math/vector.hh>

#include "dynamicRotative.hh"

#define CONTROL_FORCE_FACTOR 5

/// \class Controllable
/// \brief Controllable is a DynamicRotative with special update function
///        that moves it depending on its direction and the keys pressed.
class Controllable : public virtual DynamicRotative
{
  public:
    virtual ~Controllable() = 0;

    virtual void update() override;
  private:
    Vector dir_ = Vector();
};
