#include "takable.hh"

Takable::~Takable()
{}

bool
Takable::ready()
{
  return taker_ != nullptr;
}

Vector
Takable::takerToThis()
{
  return pos_ - taker_->pos_get();
}

void
Takable::enterTakenMode()
{
  taken_ = true;
  takerToThis_ = takerToThis();
  takerInitAngularPos_ = taker_->angularPos_get();
}

void
Takable::leaveTakenMode()
{
  taken_ = false;
  takerToThis_ = Vector();
  takerInitAngularPos_ = Vector();
}

void
Takable::mousePressed(int button, int x, int y)
{
  if (!ready())
    return;
  if (button == takeButton_)
    enterTakenMode();
  x = x;
  y = y;
}

void
Takable::mouseReleased(int button, int x, int y)
{
  if (!ready())
    return;
  if (button == takeButton_)
    leaveTakenMode();
  x = x;
  y = y;
}

void
Takable::mouseMoved(int x, int y)
{
  x = x;
  y = y;
}

void
Takable::update()
{
  if (!ready())
    return;
  if (!taken_)
    return;

  auto deltaAngles = taker_->angularPos_get() - takerInitAngularPos_;
  auto newTakerToThis = takerToThis_;
  newTakerToThis.rotate(deltaAngles[0], taker_->left());
  newTakerToThis.rotate(deltaAngles[1], taker_->upwards());

  pos_ = taker_->pos_get() + newTakerToThis;
}
