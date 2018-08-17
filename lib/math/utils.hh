#define QUARTER_ANGLE 90
#define HALF_ANGLE 180

float toRadians(float a);

class PerlinNoise
{
  public:
    PerlinNoise() = delete;
    ~PerlinNoise() = delete;
    static float get(float x, float y, unsigned int seed = 0);
  private:
    static int bijection(int x, int y);
    static float lerp(float v1, float v2, float r);
    static float delta(int xi, int yi, float x, float y, unsigned int seed);
};
