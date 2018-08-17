#include <cmath>
#include <cstdlib>

#include "utils.hh"

float toRadians(float a)
{
  return a * 0.01745329251;
}

float
PerlinNoise::get(float x, float y, unsigned int seed)
{
  int x0 = floor(x);
  int x1 = x0 + 1;
  int y0 = floor(y);
  int y1 = y0 + 1;

  float sx = x - x0;
  float sy = y - y0;

  float n0 = delta(x0, y0, x, y, seed);
  float n1 = delta(x1, y0, x, y, seed);
  float ix = lerp(n0, n1, sx);
  float n2 = delta(x0, y1, x, y, seed);
  float n3 = delta(x1, y1, x, y, seed);
  float iy = lerp(n2, n3, sx);
  return lerp(ix, iy, sy);
}

#include <iostream>

float
PerlinNoise::delta(int xi, int yi, float x, float y, unsigned int seed)
{
  srand(((unsigned int) bijection(xi, yi)) + seed);
  float angle = rand() % 360;
 
  float gradX = cos(toRadians(angle));
  float gradY = sin(toRadians(angle));

  float dx = x - xi;
  float dy = y - yi;

  return dx * gradX + dy * gradY;
}

int
PerlinNoise::bijection(int x, int y)
{
  if (x == 0 && y == 0)
    return 0;
  int n = std::max(abs(x), abs(y));
  if (y >= x)
    return 4*n*(n-1) + 2*n + 1 + x + y;
  return 4*n*(n-1) + 6*n + 1 + x + y;
}

float
PerlinNoise::lerp(float v1, float v2, float r)
{
  return (1 - r) * v1 + r * v2;
}
