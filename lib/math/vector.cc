#include "vector.hh"

Vector::Vector(float x, float y, float z)
  :  x_(x), y_(y), z_(z)
{}

float Vector::dot(Vector other) const
{
  return x_ * other.x_
       + y_ * other.y_
       + z_ * other.z_;
}

Vector Vector::cross(Vector other) const
{
  return Vector(y_ * other.z_ - z_ * other.y_,
                z_ * other.x_ - x_ * other.z_,
                x_ * other.y_ - y_ * other.x_);
}

Vector Vector::operator+(Vector other) const
{
  return Vector(x_ + other.x_,
                y_ + other.y_,
                z_ + other.z_);
}

Vector Vector::operator+=(Vector other)
{
  *this = *this + other;
  return *this;
}

Vector Vector::operator-(Vector other) const
{
  return Vector(x_ - other.x_,
                y_ - other.y_,
                z_ - other.z_);
}

Vector Vector::operator-=(Vector other)
{
  *this = *this - other;
  return *this;
}

Vector Vector::operator*(float k) const
{
  return Vector(x_ * k, y_ * k, z_ * k);
}

Vector Vector::operator*=(float k)
{
  *this = *this * k;
  return *this;
}

Vector Vector::operator/(float k) const
{
  if (k == 0)
    throw;
  return Vector(x_ / k, y_ / k, z_ / k);
}

Vector Vector::operator/=(float k)
{
  *this = *this / k;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
  os << "[" << v.x_ << ", " << v.y_ << ", " << v.z_ << "]";
  return os;
}

Vector operator*(float k, Vector v)
{
  return Vector(k * v.x_, k * v.y_, k * v.z_);
}
