#ifndef studentas_h
#define studentas_h
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "zmogus.h"
#include "myVector.h"
using namespace std;

class studentas : public zmogus
{
  private:
  int egz;
  double vid;
  Vector <int> nd;
  double med;

  public:
  studentas();
  studentas(const string &vard, const string &pavard);
  inline string getName() const { return name; }
  inline string getSurname() const { return surname; }
  Vector<int> getND() { return nd; }
  int getEgz() const { return egz; }
  double getMed() const { return med; }
  double getVid() const { return vid; }
  int ndSize() const { return nd.size(); }
  void ndSort() { sort(nd.begin(), nd.end()); }
  int ndSum() { return accumulate(nd.begin(), nd.end(), 0); }
  int getLastND() { return nd.back(); }

  void setName(string vard) { this->name = vard; }
  void setSurname(string pav) { this->surname= pav; }
  void setEgz(int egz2) { this->egz= egz2; }
  void setMed(double med2) { this->med = med2; }
  void setVid(double vid2) { this->vid = vid2; }
  void setND(int nd2) { this->nd.push_back(nd2); }
  void deleteLastNd() { this->nd.pop_back(); }
  double finalGrade(int n, int sum, int egz);
  void clearStudent() { this->name.clear(); this->surname.clear(); this->nd.clear(); this->egz = 0; this->med = 0.0; this->vid = 0.0; }      
  double median(const Vector<int> &nd, int n, int egz);
  void print() const override{};
 
  studentas(const studentas &LaikinasStudentas);
  studentas(studentas &&Laikinasstudentas);
  studentas& operator=(const studentas &Laikinasstudentas);
  studentas& operator=(studentas &&Laikinasstudentas);
  friend istringstream& operator>>(istringstream& filename, studentas &Laikinasstudentas);
  friend istream& operator>>(istream& manual, studentas &Laikinasstudentas);
  friend ostream& operator<<(ostream& console, const studentas &Laikinasstudentas);
  friend ofstream& operator<<(ofstream& filename, const studentas &Laikinasstudentas);

 ~studentas();
};
extern int number1;
extern int skaicius;
extern Vector<string> names;
extern Vector<string> surnames;
extern Vector <studentas> s; //studentai
extern int n;
extern int m;
#endif
