#include <stdexcept>

#include "matrix.hh"

Matrix::Matrix()
{
  auto row1 = std::vector<float>();
  row1.push_back(1);
  row1.push_back(0);
  row1.push_back(0);
  values_.push_back(row1);

  auto row2 = std::vector<float>();
  row2.push_back(0);
  row2.push_back(1);
  row2.push_back(0);
  values_.push_back(row2);

  auto row3 = std::vector<float>();
  row3.push_back(0);
  row3.push_back(0);
  row3.push_back(1);
  values_.push_back(row3);
}

Matrix
Matrix::identity()
{
  return Matrix();
}

Matrix
Matrix::transpose()
{
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = i + 1; j < DIM; j++)
    {
      if (i != j)
      {
        auto tmp = values_[i][j];
        values_[i][j] = values_[j][i];
        values_[j][i] = tmp;
      }
    }
  }
  return *this;
}

float
Matrix::cofactor(int i, int j)
{
  if (i < 0 || i >= DIM || j < 0 || j >= DIM)
    throw std::invalid_argument("matrix index out of range");
  int row1 = (i + 1)%DIM;
  int row2 = (i + 2)%DIM;
  int col1 = (j + 1)%DIM;
  int col2 = (j + 2)%DIM;
  int sign = (i + j)%2 == 0 ? 1 : -1;
  return sign * (values_[row1][col1]*values_[row2][col2]
    - values_[row2][col1]*values_[row1][col2]);
}

Matrix
Matrix::cofactor()
{
  auto ret = Matrix();
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
      ret.values_[i][j] = cofactor(i,j);
  }
  return ret;
}

float
Matrix::determinant()
{
  auto cof1 = cofactor(0, 0);
  auto cof2 = cofactor(1, 0);
  auto cof3 = cofactor(2, 0);
  return values_[0][0]*cof1 - values_[1][0]*cof2 + values_[2][0]*cof3;
}

Matrix
Matrix::invert()
{
  auto det = determinant();
  if (det == 0)
    throw std::invalid_argument("Cannot invert matrix with null determinant");
  auto ret = cofactor();
  ret.transpose();
  return ret / det;
}

Matrix
Matrix::operator+(Matrix rhs)
{
  auto ret = Matrix();
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
    {
      ret.values_[i][j] = values_[i][j] + rhs.values_[i][j];
    }
  }
  return ret;
}

Matrix&
Matrix::operator+=(Matrix rhs)
{
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
    {
      values_[i][j] += rhs.values_[i][j];
    }
  }
  return *this;
}

Matrix
Matrix::operator-(Matrix rhs)
{
  return (*this) + (rhs * (-1));
}

Matrix&
Matrix::operator-=(Matrix rhs)
{
  return (*this) += (rhs * (-1));
}

Matrix
Matrix::operator*(Matrix rhs)
{
  auto ret = Matrix();
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
    {
      float val = 0;
      for (auto k = 0; k < DIM; k++)
      {
        val += values_[i][k] * rhs.values_[k][j];
      }
      ret.values_[i][j] = val;
    }
  }
  return ret;
}

Matrix&
Matrix::operator*=(Matrix rhs)
{
  *this = *this * rhs;
  return *this;
}

Matrix
Matrix::operator*(float rhs)
{
  auto ret = Matrix();
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
    {
      ret.values_[i][j] *= rhs;
    }
  }
  return ret;
}

Matrix
operator*(float lhs, Matrix rhs)
{
  return rhs * lhs;
}

Matrix&
Matrix::operator*=(float rhs)
{
  *this = (*this) * rhs;
  return *this;
}

Matrix
Matrix::operator/(float rhs)
{
  if (rhs == 0)
    throw std::invalid_argument("matrix division by zero");
  auto ret = Matrix();
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
    {
      ret.values_[i][j] = values_[i][j] / rhs;
    }
  }
  return ret;
}

Matrix&
Matrix::operator/=(float lhs)
{
  if (lhs == 0)
    throw std::invalid_argument("matrix division by zero");
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
    {
      values_[i][j] /= lhs;
    }
  }
  return *this;
}

Vector
Matrix::operator*(Vector rhs)
{
  auto ret = Vector();
  for (auto i = 0; i < DIM; i++)
  {
    for (auto j = 0; j < DIM; j++)
    {
      ret[i] += values_[i][j] * rhs[j];
    }
  }
  return ret;
}
