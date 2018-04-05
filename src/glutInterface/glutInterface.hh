#pragma once

#include <GL/glut.h>

#include <keyboard/keyboard.hh>
#include <mouse/mouse.hh>

#define KEY_F1        N_KEY / 2 + GLUT_KEY_F1
#define KEY_F2        N_KEY / 2 + GLUT_KEY_F2
#define KEY_F3        N_KEY / 2 + GLUT_KEY_F3
#define KEY_F4        N_KEY / 2 + GLUT_KEY_F4
#define KEY_F5        N_KEY / 2 + GLUT_KEY_F5
#define KEY_F6        N_KEY / 2 + GLUT_KEY_F6
#define KEY_F7        N_KEY / 2 + GLUT_KEY_F7
#define KEY_F8        N_KEY / 2 + GLUT_KEY_F8
#define KEY_F9        N_KEY / 2 + GLUT_KEY_F9
#define KEY_F10       N_KEY / 2 + GLUT_KEY_F10
#define KEY_F11       N_KEY / 2 + GLUT_KEY_F11
#define KEY_F12       N_KEY / 2 + GLUT_KEY_F12
#define KEY_LEFT      N_KEY / 2 + GLUT_KEY_LEFT
#define KEY_UP        N_KEY / 2 + GLUT_KEY_UP
#define KEY_RIGHT     N_KEY / 2 + GLUT_KEY_RIGHT
#define KEY_DOWN      N_KEY / 2 + GLUT_KEY_DOWN
#define KEY_PAGE_UP   N_KEY / 2 + GLUT_KEY_PAGE_UP
#define KEY_PAGE_DOWN N_KEY / 2 + GLUT_KEY_PAGE_DOWN
#define KEY_HOME      N_KEY / 2 + GLUT_KEY_HOME
#define KEY_END       N_KEY / 2 + GLUT_KEY_END
#define KEY_INSERT    N_KEY / 2 + GLUT_KEY_INSERT
#define KEY_SHIFT     368


void keyPressed(unsigned char key, int x, int y);
void keyReleased(unsigned char key, int x, int y);
void specialKeyPressed(int key, int x, int y);
void specialKeyReleased(int key, int x, int y);
void mouseEvent(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void mousePassiveMotion(int x, int y);
