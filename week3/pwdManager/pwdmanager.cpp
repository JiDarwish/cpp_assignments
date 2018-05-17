#include <iostream>
#include "pwdmanager.h"

void pwdmanager::verwerkLetter(bool &hoofd, bool &klein, bool &cijfer, char c)
{
  if (std::isdigit(c))
  {
    cijfer = true;
  }
  else if (std::isalpha(c))
  {
    if (std::islower(c))
    {
      klein = true;
    }
    else
    {
      hoofd = true;
    }
  }
}

bool pwdmanager::werdEerderGebruikt(std::string newPass)
{
  for (std::string str : pwds)
  {
    if (!str.compare(newPass))
    {
      return true;
    }
  }
  return false;
}

void pwdmanager::voegAanPwds(std::string newPass)
{
  currentPwd = newPass;
  pwds.push_back(newPass);
}

pwdmanager::pwdmanager(uint len)
{
  pwdLen = len;
}

bool pwdmanager::newPassword(std::string newPass)
{
  // Lengte is goed?
  if (!newPass.length() >= pwdLen)
  {
    return false;
  }

  bool hoofdLetter = false;  // tenminste 1 hoofdletter aanwezig
  bool kleineLetter = false; // tenminste 1 kleine letter aanwezig
  bool cijfer = false;       // tenminste 1 cijfer aanwezig

  for (int i = 0; i < newPass.length(); i++)
  {
    char letterChecked = newPass[i];
    verwerkLetter(hoofdLetter, kleineLetter, cijfer, letterChecked);
    if (hoofdLetter && kleineLetter && cijfer)
    {
      if (werdEerderGebruikt(newPass))
      {
        return false;
      }

      voegAanPwds(newPass);
      return true;
    }
  }
  return false;
}

int main()
{
  pwdmanager manager = pwdmanager(4);
  std::cout << manager.newPassword("Aa1as") << std::endl;
  std::cout << manager.newPassword("AsdfE2s") << std::endl;
  std::cout << manager.newPassword("AsdfE2s") << std::endl;

  return 0;
}