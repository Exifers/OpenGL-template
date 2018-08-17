#pragma once
#include <list>

#include <math/vector.hh>
#include <object/dynamicRotative.hh>
#include <object/takable.hh>

class Renderable : public virtual DynamicRotative, public virtual Takable
{
  public:
    Renderable();
    ~Renderable();
    Renderable(Vector pos, Vector angularPos);
    Renderable(Vector pos);

    virtual void render();

    virtual void update() override;

    static void renderAll();

    void moveFrame();
    void resetFrame();
  private:
    virtual void renderingWrapper() = 0;
    static std::list<Renderable *> instances_;
};
