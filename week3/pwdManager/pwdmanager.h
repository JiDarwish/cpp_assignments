#ifndef PWDMANAGER_H
#define PWDMANAGER_H

#include <string>
#include <deque>

class pwdmanager
{
    // hier je eigen PRIVATE data items en methoden !

  private:
    uint pwdLen;
    std::deque<std::string> pwds;
    std::string currentPwd;
    void verwerkLetter(bool &, bool &, bool &, char);
    bool werdEerderGebruikt(std::string);
    void voegAanPwds(std::string);

  public:
    pwdmanager(uint);
    bool newPassword(std::string);
};

#endif // einde PWDMANAGER_H
