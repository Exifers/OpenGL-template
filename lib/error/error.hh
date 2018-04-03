#include <string>
#include <iostream>

class Error
{
  public:
    Error() = default;
    Error(char status);

    Error& operator<<(std::string& str);
    Error& operator<<(const char *str);
    Error& operator<<(const unsigned char *str);
    Error& operator<<(Error e);

  private:
    std::ostream& ostr_ = std::cerr;
    char status_ = -1;
};
