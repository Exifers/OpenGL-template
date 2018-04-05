#pragma once

#include <ostream>
#include <list>
#include <vector>

#define MOUSE_NB_BUTTON     3

#define MOUSE_NO_BUTTON    -1
#define MOUSE_RIGHT_BUTTON  0
#define MOUSE_MIDDLE_BUTTON 1
#define MOUSE_LEFT_BUTT0N   2

extern bool mouseState[];

class MouseListener
{
  public:
    static void applyMouseEventOnAll(void);
  protected:
    MouseListener();
    ~MouseListener();
    virtual void MousePressed(int x, int y) = 0;
    virtual void MouseReleased(int x, int y) = 0;
    virtual void MouseMoved(int x, int y) = 0;
  private:
    static std::list<MouseListener *> instances_;
    static void applyMousePressedOnAll();
    static void applyMouseReleasedOnAll();
    static void applyMouseMovedOnAll();
};

struct mouseEvent
{
  int x;
  int y;
  char button;
};

class MouseEventQueue
{
  protected:
    using mouseEvent_t = struct mouseEvent;
    using mouseEventQueue_t = std::vector<mouseEvent_t>;
  public:
    virtual ~MouseEventQueue() = 0;

  mouseEvent_t pick();
  mouseEvent_t pop();

  /// Returned by pick and pop if the stack is empty.
  static const constexpr mouseEvent_t notFound = {-1, -1, MOUSE_NO_BUTTON};

  friend std::ostream& operator<<(std::ostream& ostr, MouseEventQueue& q);

  protected:
  MouseEventQueue() = default;
  mouseEventQueue_t queue_;

  void push(mouseEvent_t event);
};

class MousePressedQueue : public MouseEventQueue
{
  public:
  static MousePressedQueue& instance();

  /// Function to be called by the API
  static void MousePressed(int x, int y, char button);

  protected:
  MousePressedQueue() = default;
};

class MouseReleasedQueue : public MouseEventQueue
{
  public:
  static MouseReleasedQueue& instance();

  /// Function to be called by the API
  static void MouseReleased(int x, int y, char button);

  protected:
  MouseReleasedQueue() = default;
};

class MouseMovedQueue : public MouseEventQueue
{
  public:
  static MouseMovedQueue& instance();

  /// Function to be called by the API
  static void MouseMoved(int x, int y);

  protected:
  MouseMovedQueue() = default;
};
