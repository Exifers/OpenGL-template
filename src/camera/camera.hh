#include <ostream>

#include <keyboard/keyboard.hh>
#include <math/vector.hh>
#include <dynamic/dynamic.hh>
#include <glutInterface/glutInterface.hh>

class Camera : public Controllable
{
  public:
    static Camera instance();
    void update() override;

    friend std::ostream& operator<<(std::ostream& ostr, Camera c);
  private:
    Camera() = default;
};
