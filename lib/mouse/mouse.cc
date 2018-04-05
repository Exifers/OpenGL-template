#include "mouse.hh"

bool mouseState[MOUSE_NB_BUTTON] = {false};
std::pair<int, int> mousePos = std::pair<int, int>(0, 0);

std::list<MouseListener *> MouseListener::instances_;

MouseListener::MouseListener()
{
  instances_.push_back(this);
}

MouseListener::~MouseListener()
{
  instances_.remove(this);
}

void
MouseListener::applyMouseEventOnAll()
{
  applyMousePressedOnAll();
  applyMouseReleasedOnAll();
  applyMouseMovedOnAll();
}

void
MouseListener::applyMousePressedOnAll()
{
  auto mpEvent = MousePressedQueue::instance().pop();
  if (mpEvent.isNotFound())
    return;
  mouseState[mpEvent.button] = true;
  for (auto it = instances_.begin(); it != instances_.end(); it++)
  {
    (*it)->mousePressed(mpEvent.button, mpEvent.x, mpEvent.y);
  }
}

void
MouseListener::applyMouseReleasedOnAll()
{
  auto mrEvent = MouseReleasedQueue::instance().pop();
  if (mrEvent.isNotFound())
    return;
  mouseState[mrEvent.button] = false;
  for (auto it = instances_.begin(); it != instances_.end(); it++)
  {
    (*it)->mouseReleased(mrEvent.button, mrEvent.x, mrEvent.y);
  }
}

void
MouseListener::applyMouseMovedOnAll()
{
  auto mvEvent = MouseMovedQueue::instance().pop();
  if (mvEvent.isNotFound())
    return;
  mousePos.first  = mvEvent.x;
  mousePos.second = mvEvent.y;
  for (auto it = instances_.begin(); it != instances_.end(); it++)
  {
    (*it)->mouseMoved(mvEvent.x, mvEvent.y);
  }
}

struct mouseEvent
MouseEventQueue::pick()
{
  if (queue_.size() == 0)
    return notFound;
  return queue_.front();
}

struct mouseEvent
MouseEventQueue::pop()
{
  if (queue_.size() == 0)
    return notFound;
  auto ret = queue_.front();
  queue_.pop_front();
  return ret;
}

void
MouseEventQueue::push(struct mouseEvent event)
{
  queue_.push_back(event);
}

MousePressedQueue&
MousePressedQueue::instance()
{
  static MousePressedQueue instance;
  return instance;
}

MouseReleasedQueue&
MouseReleasedQueue::instance()
{
  static MouseReleasedQueue instance;
  return instance;
}

MouseMovedQueue&
MouseMovedQueue::instance()
{
  static MouseMovedQueue instance;
  return instance;
}

void
MousePressedQueue::mousePressed(int x, int y, int button)
{
  instance().push({x, y, button});
}

void
MouseReleasedQueue::mouseReleased(int x, int y, int button)
{
  instance().push({x, y, button});
}

void
MouseMovedQueue::mouseMoved(int x, int y)
{
  instance().push({x, y, MOUSE_BUTTON_NONE});
}

MouseEventQueue::~MouseEventQueue()
{}
