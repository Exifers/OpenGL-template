#include <math/vector.hh>

#include "renderable.hh"

class Light : public virtual Renderable
{
  public:
    Light() = default;
    Light(Vector pos, Vector angularPos);
  private:
    virtual void renderingWrapper() override;
};
