#pragma once

#include <math/vector.hh>

class Dynamic
{
  public:
    Dynamic() = default;
    ~Dynamic() = default;

    void update(void);
    void apply_force(Vector force);

    float& mass_get(void);
    const float& mass_get() const;
    void mass_set(float mass);

    float& intr_friction_get();
    const float& intr_friction_get() const;
    void intr_friction_set(float intr_friction);

    Vector& pos_get();
    const Vector& pos_get() const;
    void pos_set(Vector pos);

    Vector& vel_get();
    const Vector& vel_get() const;
    void vel_set(Vector vel);

    Vector& acc_get();
    const Vector& acc_get() const;
    void acc_set(Vector acc);
  private:
    float mass_ = 1;
    float intr_friction_ = 1;
    Vector pos_;
    Vector vel_;
    Vector acc_;
};

#include "dynamic.hxx"
