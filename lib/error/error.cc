#include <error/error.hh>

Error::Error(char status)
  : status_(status)
{}

Error&
Error::operator<<(std::string& str)
{
  ostr_ << str;
  return *this;
}

Error&
Error::operator<<(const char *str)
{
  ostr_ << str;
  return *this;
}

Error&
Error::operator<<(const unsigned char *str)
{
  ostr_ << str;
  return *this;
}

Error&
Error::operator<<(Error e)
{
  ostr_ << std::endl;
  std::exit(e.status_);
}
