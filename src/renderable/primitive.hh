#pragma once

#include <math/vector.hh>
#include <mouse/mouse.hh>

#include "renderable.hh"

class Sphere : public virtual Renderable
{
  public:
    Sphere() = default;
    Sphere(Vector pos, Vector rot, float r);
    Sphere(Vector pos, float r, int slices, int stacks);
  private:
    void renderingWrapper() override;
  protected:
    float r_ = 1;
    int slices_ = 50;
    int stacks_ = 50;
};

class Cube : public virtual Renderable
{
  public:
    Cube() = default;
    Cube(float c);
    Cube(Vector pos, float c);
    Cube(Vector pos, Vector rot, float c);

    void mousePressed(int button, int x, int y) override;
    void mouseReleased(int button, int x, int y) override;
    void mouseMoved(int x, int y) override;
  private:
    void renderingWrapper() override;
  protected:
    float c_ = 1;
};

class Plane : public virtual Renderable
{
  public:
    Plane() = default;

    Vector& dimension_get();
    const Vector& dimension_get() const;

    Vector& side_get();
    const Vector& side_get() const;
  private:
    void renderingWrapper() override;
  protected:
    Vector dimension_ = Vector(10, 0, 10);
    Vector side_ = Vector(10, 0, 0);
};
