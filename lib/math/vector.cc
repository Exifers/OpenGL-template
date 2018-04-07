#include <stdexcept>
#include <cmath>

#include "vector.hh"
#include "utils.hh"

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

float Vector::size() const
{
  return sqrt(dot(*this));
}

Vector Vector::normalized() const
{
  auto ret = Vector(x_, y_, z_);
  auto s = size();
  if (s == 0)
    return ret;
  return ret / s;
}

Vector Vector::rotate(float angle, Vector orth)
{
  orth = orth.normalized();
  if (orth.size() == 0)
    throw std::invalid_argument("Cannot rotate vector around null axis");

  orth[2] *= -1;
  (*this)[2] *= -1;

  auto rotated = *this * cos(toRadians(angle))
       + orth * (1 - cos(toRadians(angle))) * (this->dot(orth))
       + orth.cross(*this) * sin(toRadians(angle));
  *this = rotated;

  (*this)[2] *= -1;

  return *this;
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

Vector Vector::operator-() const
{
  return Vector() - *this;
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

Vector Vector::operator*(Vector other) const
{
  return Vector(
    x_ * other.x_,
    y_ * other.y_,
    z_ * other.z_);
}

Vector Vector::operator*=(Vector other)
{
  *this = *this * other;
  return *this;
}

Vector Vector::operator/(float k) const
{
  if (k == 0)
    throw std::invalid_argument("Cannot divide vector by 0");
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

float&
Vector::operator[](int index)
{
  switch(index)
  {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
    default:
      throw std::invalid_argument("vector index out of range");
  }
}

const float&
Vector::operator[](int index) const
{
  switch(index)
  {
    case 0:
      return x_;
    case 1:
      return y_;
    case 2:
      return z_;
    default:
      throw std::invalid_argument("vector index out of range");
  }
}
