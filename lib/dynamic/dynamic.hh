#pragma once

#include <list>

#include <math/vector.hh>
#include <math/matrix.hh>
#include <keyboard/keyboard.hh>
#include <glutInterface/glutInterface.hh>

class DynamicBase
{
  public:
    DynamicBase();
    virtual ~DynamicBase() = 0;

    virtual void update();
    void apply_force(Vector force);
    static void updateAll();

    float& mass_get();
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
  protected:
    float mass_ = 1;
    float intr_friction_ = 0.2;
    Vector pos_;
    Vector vel_;
    Vector acc_;

    static std::list<DynamicBase *> instances_;
};

class DynamicRotative : public DynamicBase
{
  public:
    DynamicRotative() = default;
    virtual ~DynamicRotative() = 0;

    virtual void update() override;

    Vector& angularPos_get();
    const Vector& angularPos_get() const;

    Vector& angularVel_get();
    const Vector& angularVel_get() const;

    Vector& intrAngularFriction_get();
    const Vector& intrAngularFriction_get() const;

    Matrix& inertia_get();
    const Matrix& inertia_get() const;

    Vector& torque_get();
    const Vector& torque_get() const;

  protected:
    Vector angularPos_;
    Vector angularVel_;
    Vector intrAngularFriction_ = Vector(1, 1, 1);
    Matrix inertia_ = Matrix::identity();
    Vector torque_;
};

class Controllable : public KeyboardListener, public DynamicRotative
{
  public:
    virtual ~Controllable() = 0;

    void keyPressed(int key) override;
    void keyReleased(int key) override;
  protected:
    Vector dir_;
};

#include "dynamic.hxx"
