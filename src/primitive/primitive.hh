#pragma once
#include <list>

#include <math/vector.hh>

class Primitive
{
  public:
    Primitive();
    ~Primitive();
    Primitive(Vector pos, Vector rot);
    Primitive(Vector pos);

    virtual void render();

    static void renderAll();

    void moveFrame();
    void resetFrame();

    Vector& pos_get();
    const Vector& pos_get() const;
    Vector& rot_get();
    const Vector& rot_get() const;
  protected:
    Vector pos_;
    Vector rot_;
  private:
    virtual void renderingWrapper() = 0;
    static std::list<Primitive *> instances_;
};

class Sphere : public Primitive
{
  public:
    Sphere() = default;
    Sphere(Vector pos, Vector rot, float r);
    Sphere(Vector pos, float r, int slices, int stacks);

    void renderingWrapper() override;
  protected:
    float r_;
    int slices_ = 50;
    int stacks_ = 50;
};
