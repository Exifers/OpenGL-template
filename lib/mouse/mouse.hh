#pragma once

#include <ostream>
#include <list>

#define MOUSE_NB_BUTTON      3

#define MOUSE_BUTTON_NONE   -1
#define MOUSE_BUTTON_LEFT    0
#define MOUSE_BUTTON_MIDDLE  1
#define MOUSE_BUTTON_RIGHT   2

#define MOUSE_B_NF -1
#define MOUSE_X_NF -1
#define MOUSE_Y_NF -1

extern bool mouseState[];
extern std::pair<int, int> mousePos;

class MouseListener
{
  public:
    static void applyMouseEventOnAll();
  protected:
    MouseListener();
    ~MouseListener();
    virtual void mousePressed(int button, int x, int y) = 0;
    virtual void mouseReleased(int button, int x, int y) = 0;
    virtual void mouseMoved(int x, int y) = 0;
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
  int button;
  bool isNotFound()
  {
    return x      == MOUSE_X_NF
        && y      == MOUSE_Y_NF
        && button == MOUSE_B_NF;
  }
};

class MouseEventQueue
{
  protected:
    using mouseEvent_t = struct mouseEvent;
    using mouseEventQueue_t = std::list<mouseEvent_t>;
  public:
    virtual ~MouseEventQueue() = 0;

  mouseEvent_t pick();
  mouseEvent_t pop();

  /// Returned by pick and pop if the stack is empty.
  static const constexpr mouseEvent_t notFound = {MOUSE_X_NF,
                                                  MOUSE_Y_NF,
                                                  MOUSE_B_NF};

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
  static void mousePressed(int x, int y, int button);

  protected:
  MousePressedQueue() = default;
};

class MouseReleasedQueue : public MouseEventQueue
{
  public:
  static MouseReleasedQueue& instance();

  /// Function to be called by the API
  static void mouseReleased(int x, int y, int button);

  protected:
  MouseReleasedQueue() = default;
};

class MouseMovedQueue : public MouseEventQueue
{
  public:
  static MouseMovedQueue& instance();

  /// Function to be called by the API
  static void mouseMoved(int x, int y);
  static bool wrapping;

  protected:
  MouseMovedQueue() = default;
};
