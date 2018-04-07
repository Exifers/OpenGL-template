#pragma once
#include <ostream>

#include <keyboard/keyboard.hh>
#include <math/vector.hh>
#include <object/controllable.hh>
#include <glutInterface/glutInterface.hh>
#include <mouse/mouse.hh>

class Camera : public Controllable
{
  public:
    static Camera& instance();
    void update() override;

    void moveFrame() const;

    float& bufferAngle_get();
    const float& bufferAngle_get() const;

    friend std::ostream& operator<<(std::ostream& ostr, Camera c);
  private:
    Camera() = default;
    void orientate(int x, int y, int width, int height);
    static void centerCursor();
    static bool cursorOnSide();
    static bool cursorHasInitValue();
    static void setCursorOnMiddle();

    float bufferAngle_ = 0;
    float localAngle_ = 0;
};
