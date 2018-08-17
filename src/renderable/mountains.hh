#pragma once

#include <vector>

#include <math/vector.hh>

#include "renderable.hh"

/// \class Mountains
/// \brief Generates a mountains-like mesh based on perlin noise. \a dimension
///        vector stores : length, height, width respectively.
class Mountains : public virtual Renderable
{
  using vertices_t = std::vector<std::vector<Vector>>;

  public:
    Mountains();
    Vector& dimension_get();
    const Vector& dimension_get() const;

    float& sharpness_get();
    const float& sharpness_get() const;

    float& step_get();
    const float& step_get() const;
  private:
    void renderingWrapper() override;
    vertices_t vertices_ = vertices_t();
    void generateVertices();
  protected:
    float sharpness_ = 0.1;
    Vector dimension_ = Vector(100, 10, 100);
    float step_ = 1.2;
};
