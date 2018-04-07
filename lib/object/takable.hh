#pragma once

#include <math/vector.hh>
#include <mouse/mouse.hh>

#include "staticBase.hh"
#include "controllable.hh"

/// \class Takable
/// \brief Takable is an object that can be moved according to the camera
///        movements once it has been taken.
class Takable : public virtual StaticBase, public MouseListener
{
  public:
    virtual ~Takable() = 0;

    virtual void update();

    virtual void mousePressed(int button, int x, int y) override;
    virtual void mouseReleased(int button, int x, int y) override;
    virtual void mouseMoved(int x, int y) override;

    Controllable *& taker_get();
    Controllable * const & taker_get() const;

    bool& taken_get();
    const bool& taken_get() const;
  protected:
    bool taken_ = false;
    Controllable *taker_ = nullptr;
    Vector takerToThis_ = Vector();
    Vector takerInitAngularPos_ = Vector();
    int takeButton_ = MOUSE_BUTTON_LEFT;
  private:
    bool ready();
    Vector takerToThis();
    void enterTakenMode();
    void leaveTakenMode();
};

#include "takable.hxx"
