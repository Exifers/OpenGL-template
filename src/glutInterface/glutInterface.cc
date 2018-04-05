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
  button = button;
  state = state;
  x = x;
  y = y;
}

void mouseMotion(int x, int y)
{
  x = x;
  y = y;
}

void mousePassiveMotion(int x, int y)
{
  x = x;
  y = y;
}
