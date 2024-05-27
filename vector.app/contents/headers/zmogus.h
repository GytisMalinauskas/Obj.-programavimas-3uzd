#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
using namespace std;

class zmogus{
  protected:
  string name, surname;
  zmogus() : name(""), surname("") {};
  zmogus(const string &vard, const string &pav) : name(vard), surname(pav) {};
  virtual ~zmogus() {};
  public:
  inline string getName() const {return name;}
  inline string getSurname() const{return surname;}
  void setName(string vard){this->name = vard;}
  void setSurname(string pav){this->surname = pav;}
  virtual void print() const=0;
};

#endif