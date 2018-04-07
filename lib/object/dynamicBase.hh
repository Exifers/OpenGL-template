#pragma once

#include <list>

#include "staticBase.hh"

class DynamicBase : public virtual StaticBase
{
  public:
    DynamicBase();
    virtual ~DynamicBase() = 0;

    virtual void update();
    static void updateAll();

    void force_set(Vector force);
    void force_add(Vector force);

    float& mass_get();
    const float& mass_get() const;

    float& friction_get();
    const float& friction_get() const;

    Vector& vel_get();
    const Vector& vel_get() const;

    Vector& acc_get();
    const Vector& acc_get() const;
  protected:
    float mass_ = 1;
    float friction_ = 0.7;
    Vector vel_ = Vector();
    Vector acc_ = Vector();

    static std::list<DynamicBase *> instances_;
};

#include "dynamicBase.hxx"
