#include <mouse/mouse.hh>

#include "element.hh"

namespace gui
{
  class Button : public Element, public MouseListener
  {
    public:
      Button() = default;

      void mousePressed(int button, int x, int y) override;
      void mouseReleased(int button, int x, int y) override;
      void mouseMoved(int x, int y) override;

      void display() override;
    private:
  };
}
