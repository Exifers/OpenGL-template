#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>

#include <math/utils.hh>

#include "mountains.hh"

Mountains::Mountains()
{
  generateVertices();
}

void
Mountains::generateVertices()
{
  float length = dimension_.x_get();
  float height = dimension_.y_get();
  float width  = dimension_.z_get();

  for (float x = pos_.x_get(); x < pos_.x_get() + length; x += step_)
  {
    auto row = std::vector<Vector>();
    for (float z = pos_.z_get(); z < pos_.z_get() + width; z += step_)
    {
      float y = height * PerlinNoise::get(x * sharpness_, z * sharpness_);
      row.push_back(Vector(x,y,z));
    }
    vertices_.push_back(row);
  }
}

void
Mountains::renderingWrapper()
{
  glBegin(GL_TRIANGLE_STRIP);
  for (size_t i = 0; i < vertices_.size() - 1; i++)
  {
    for (size_t j = 0; j < vertices_[0].size(); j++)
    {
      auto v1 = vertices_[i    ][j];
      auto v2 = vertices_[i + 1][j];

      glVertex3f(v1.x_get(), v1.y_get(), v1.z_get());
      glVertex3f(v2.x_get(), v2.y_get(), v2.z_get());

    }
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
  }
  glEnd();
}

Vector&
Mountains::dimension_get()
{
  return dimension_;
}

const Vector&
Mountains::dimension_get() const
{
  return dimension_;
}

float&
Mountains::sharpness_get()
{
  return sharpness_;
}

const float&
Mountains::sharpness_get() const
{
  return sharpness_;
}

float&
Mountains::step_get()
{
  return step_;
}

const float&
Mountains::step_get() const
{
  return step_;
}
