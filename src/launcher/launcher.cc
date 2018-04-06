#include <iostream>

#include <launcher/launcher.hh>
#include <launcher/handlers.hh>
#include <error/error.hh>
#include <glutInterface/glutInterface.hh>
#include <mouse/mouse.hh>

Launcher::Launcher(int argc, char **argv)
{
  Launcher();
  init_window(argc, argv);
  set_handlers();
  init();
}

void
Launcher::init_window(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Araktazia");
  glutFullScreen();
  glutSetCursor(GLUT_CURSOR_NONE);
  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
}

void
Launcher::reshape(int width, int height)
{
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
}

void
Launcher::set_handlers()
{
  glutDisplayFunc(display);
  glutReshapeFunc(Launcher::reshape);
  glutKeyboardFunc(keyPressed);
  glutKeyboardUpFunc(keyReleased);
  glutSpecialFunc(specialKeyPressed);
  glutSpecialUpFunc(specialKeyReleased);
  glutMouseFunc(mouseEvent);
  glutMotionFunc(mouseMotion);
  glutPassiveMotionFunc(mousePassiveMotion);
}

void
Launcher::initGL()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}

void
Launcher::initGlew()
{
  GLenum err = glewInit();
  if (err != GLEW_OK)
    Error() << "glewInit failed: " << glewGetErrorString(err) << Error(1);
  else
    std::cerr << "Glew initialized using " << glewGetString(GLEW_VERSION)
      << std::endl;
}

void
Launcher::init()
{
  initGL();
  initGlew();
}

void
Launcher::launch()
{
  glutMainLoop();
}

Launcher&
Launcher::instance(int argc, char **argv)
{
  static Launcher l(argc, argv);
  return l;
}
