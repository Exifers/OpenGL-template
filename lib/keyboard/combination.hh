#include <list>

class Combination
{
  public:
  protected:
    /// keys that need to be pressed for the combination to be true
    std::list<bool *> pressed_;
    /// keys that need to be released for the combination to be true
    std::list<bool *> released_;
}
