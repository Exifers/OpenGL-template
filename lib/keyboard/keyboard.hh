#pragma once

#define N_KEY 512

#include <ostream>
#include <vector>
#include <list>

class KeyboardListener
{
  public:
    static void applyKeyEventsOnAll(void);
  protected:
    KeyboardListener();
    ~KeyboardListener();
    virtual void keyPressed(int key) = 0;
    virtual void keyReleased(int key) = 0;
  private:
    static std::list<KeyboardListener *> instances_;
    static void applyKeyPressedOnAll(void);
    static void applyKeyReleasedOnAll(void);
};

/// \class KeyEventQueue
/// \brief Wrapper on queue container to store all key events.
class KeyEventQueue
{
  protected:
  using key_t = int;
  using keyEventQueue_t = std::vector<key_t>;

  public:
  virtual ~KeyEventQueue() = 0;

  key_t pick();
  key_t pop();

  static const key_t notFound = -1;

  friend std::ostream& operator<<(std::ostream& ostr, KeyEventQueue& q);

  protected:
  KeyEventQueue() = default;
  keyEventQueue_t queue_;

  void push(key_t key);
};

class KeyPressedQueue : public KeyEventQueue
{
  public:
  static KeyPressedQueue& instance();

  /// Function to be called by the API.
  static void keyPressed(key_t key);

  protected:
  KeyPressedQueue() = default;
};

class KeyReleasedQueue : public KeyEventQueue
{
  public:
  static KeyReleasedQueue& instance();

  /// Function to be called by the API.
  static void keyReleased(key_t key);

  protected:
  KeyReleasedQueue() = default;
};

extern bool keyStates[];
