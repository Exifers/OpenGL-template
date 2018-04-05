#include "glutInterface.hh"

void keyPressed(unsigned char key, int x, int y)
{
  KeyPressedQueue::keyPressed(key);
  x = x;
  y = y;
}

void keyReleased(unsigned char key, int x, int y)
{
  KeyReleasedQueue::keyReleased(key);
  x = x;
  y = y;
}

void specialKeyPressed(int key, int x, int y)
{
  KeyPressedQueue::keyPressed(N_KEY / 2 + key);
  x = x;
  y = y;
}

void specialKeyReleased(int key, int x, int y)
{
  KeyReleasedQueue::keyReleased(N_KEY / 2 + key);
  x = x;
  y = y;
}

void mouseEvent(int button, int state, int x, int y)
{
  if (state == 0)
  {
    switch(button)
    {
      case 0:
        MousePressedQueue::mousePressed(x, y, MOUSE_BUTTON_LEFT);
        break;
      case 1:
        MousePressedQueue::mousePressed(x, y, MOUSE_BUTTON_MIDDLE);
        break;
      case 2:
        MousePressedQueue::mousePressed(x, y, MOUSE_BUTTON_RIGHT);
        break;
      default:
        break;
    }
  }
  else
  {
    switch(button)
    {
      case 0:
        MouseReleasedQueue::mouseReleased(x, y, MOUSE_BUTTON_LEFT);
        break;
      case 1:
        MouseReleasedQueue::mouseReleased(x, y, MOUSE_BUTTON_MIDDLE);
        break;
      case 2:
        MouseReleasedQueue::mouseReleased(x, y, MOUSE_BUTTON_RIGHT);
        break;
      default:
        break;
    }
  }
}

void mouseMotion(int x, int y)
{
  mousePassiveMotion(x, y);
}

void mousePassiveMotion(int x, int y)
{
  MouseMovedQueue::mouseMoved(x,y);
}
