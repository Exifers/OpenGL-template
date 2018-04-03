#pragma once

#define DIM 3

#include <vector>
#include "vector.hh"

class Matrix
{
  using matrix_t = std::vector<std::vector<float>>;
  public:
    Matrix();

    static Matrix identity();

    Matrix transpose();
    float cofactor(int i, int j);
    Matrix cofactor();
    float determinant();
    Matrix invert();

    Matrix operator+(Matrix rhs);
    Matrix& operator+=(Matrix rhs);

    Matrix operator-(Matrix rhs);
    Matrix& operator-=(Matrix rhs);

    Matrix operator*(Matrix rhs);
    Matrix& operator*=(Matrix rhs);

    Matrix operator*(float rhs);
    friend Matrix operator*(float lhs, Matrix rhs);
    Matrix& operator*=(float rhs);

    Matrix operator/(float rhs);
    Matrix& operator/=(float rhs);

    Vector operator*(Vector rhs);
  private:
    matrix_t values_;
};
