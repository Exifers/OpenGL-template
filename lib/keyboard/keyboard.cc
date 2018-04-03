#define N_KEY 512

#include "keyboard.hh"

/*--------------------
  | KeyboardListener |
  --------------------*/

bool keyStates[N_KEY] = {false};

std::list<KeyboardListener *> KeyboardListener::instances_;

KeyboardListener::KeyboardListener()
{
  instances_.push_back(this);
}

KeyboardListener::~KeyboardListener()
{
  instances_.remove(this);
}

void
KeyboardListener::applyKeyPressedOnAll(void)
{
  auto key = KeyPressedQueue::instance().pop();
  if (key != KeyEventQueue::notFound)
  {
    keyStates[key] = true;
    for (auto it = instances_.begin(); it != instances_.end(); it++)
      (*it)->keyPressed(key);

  }
}

void
KeyboardListener::applyKeyReleasedOnAll(void)
{
  auto key = KeyReleasedQueue::instance().pop();
  if (key != KeyEventQueue::notFound)
  {
    keyStates[key] = false;
    for (auto it = instances_.begin(); it != instances_.end(); it++)
      (*it)->keyReleased(key);
  }
}

void
KeyboardListener::applyKeyEventsOnAll(void)
{
  applyKeyPressedOnAll();
  applyKeyReleasedOnAll();
}

/*-----------------
  | KeyEventQueue |
  -----------------*/

KeyEventQueue::key_t
KeyEventQueue::pick()
{
  if (queue_.size() == 0)
    return notFound;
  return queue_.front();
}

KeyEventQueue::key_t
KeyEventQueue::pop()
{
  if (queue_.size() == 0)
    return notFound;
  auto ret = queue_.front();
  queue_.erase(queue_.begin());
  return ret;
}

void
KeyEventQueue::push(key_t key)
{
  queue_.push_back(key);
}

KeyEventQueue::~KeyEventQueue()
{}

std::ostream&
operator<<(std::ostream& ostr, KeyEventQueue& q)
{
  ostr << "[";
  for (auto it = q.queue_.begin(); it != q.queue_.end(); it++)
  {
    ostr << *it;
    if (++it != q.queue_.end())
      ostr << ", ";
    it--;
  }
  ostr << "]";
  return ostr;
}

KeyPressedQueue&
KeyPressedQueue::instance()
{
  static KeyPressedQueue instance;
  return instance;
}

void
KeyPressedQueue::keyPressed(key_t key)
{
  instance().push(key);
}

KeyReleasedQueue&
KeyReleasedQueue::instance()
{
  static KeyReleasedQueue instance;
  return instance;
}

void
KeyReleasedQueue::keyReleased(key_t key)
{
  instance().push(key);
}
