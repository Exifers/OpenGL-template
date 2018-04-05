#pragma once

#include <iostream>

class Vector
{
  public:
    Vector() = default;
    Vector(float x, float y, float z);
    ~Vector() = default;

    float dot(Vector other) const;
    Vector cross(Vector other) const;
    Vector normalized() const;
    float size() const;

    Vector operator+(Vector other) const;
    Vector operator+=(Vector other);
    Vector operator-(Vector other) const;
    Vector operator-=(Vector other);
    Vector operator*(float k) const;
    Vector operator*=(float k);
    Vector operator*(Vector other) const;
    Vector operator*=(Vector other);
    Vector operator/(float k) const;
    Vector operator/=(float k);
    float& operator[](int index);
    const float& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend Vector operator*(float k, Vector v);
  private:
    float x_;
    float y_;
    float z_;
};
