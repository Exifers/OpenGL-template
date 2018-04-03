#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

class Launcher
{
  public:
    static Launcher& instance(int argc, char **argv);
    ~Launcher() = default;

    Launcher(const Launcher&) = delete;
    Launcher& operator=(const Launcher&) = delete;

    void launch();
  private:
    Launcher() = default;
    Launcher(int argc, char **argv);

    void init_window(int argc, char **argv);
    void set_handlers();
    void init();
    void initGL();
    void initGlew();
    static void reshape(int width, int height);
};
