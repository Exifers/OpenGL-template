#include <object/staticBase.hh>

namespace gui
{
  class Element : public StaticBase
  {
    public:
      virtual ~Element() = 0;
      virtual void display() = 0;

      void displayAll();
    private:
      void displaySetup();
  };
}
