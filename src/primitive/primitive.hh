#pragma once
#include <list>

#include <math/vector.hh>
#include <object/dynamicRotative.hh>
#include <object/takable.hh>
#include <mouse/mouse.hh>

#include <camera/camera.hh>

class Primitive : public virtual DynamicRotative, public virtual Takable
{
  public:
    Primitive();
    ~Primitive();
    Primitive(Vector pos, Vector angularPos);
    Primitive(Vector pos);

    virtual void render();

    virtual void update() override;

    static void renderAll();

    void moveFrame();
    void resetFrame();
  private:
    virtual void renderingWrapper() = 0;
    static std::list<Primitive *> instances_;
};

class Sphere : public virtual Primitive
{
  public:
    Sphere() = default;
    Sphere(Vector pos, Vector rot, float r);
    Sphere(Vector pos, float r, int slices, int stacks);

    void renderingWrapper() override;
  protected:
    float r_ = 1;
    int slices_ = 50;
    int stacks_ = 50;
};

class Cube : public virtual Primitive
{
  public:
    Cube() = default;
    Cube(float c);
    Cube(Vector pos, float c);
    Cube(Vector pos, Vector rot, float c);

    void mousePressed(int button, int x, int y) override;
    void mouseReleased(int button, int x, int y) override;
    void mouseMoved(int x, int y) override;

    void renderingWrapper() override;
  protected:
    float c_ = 1;
};
