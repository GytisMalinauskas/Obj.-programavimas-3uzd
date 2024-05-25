#ifndef function_h
#define function_h
#include <cstdio>
#include <locale>
#include <time.h>
#include <limits>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring> 
#include <cerrno>
#include <random>
#include <chrono>
#include <cassert>
#include "studentas.h"
#include "error.h"
#include "zmogus.h"
#include "myVector.h"

void Skaicius1(Vector<studentas>& s, int &m, int skaicius, int MinP, int MaxP);
void Skaicius2(Vector<studentas>& s, int skaicius, int MinP, int MaxP);
void FailoSkaitymas(Vector <studentas> &s, string &duomPav);
void VarduGeneravimui();
void Sorting(Vector<studentas>& s,Vector<studentas> &k, Vector <studentas> &l, string choice, int rikiavimas, int strategy);
void Isvedimas(Vector <studentas> s, Vector <studentas> &l, Vector <studentas> &k);
bool rikiavimasVid(studentas& s1, studentas& s2);
bool rikiavimasMed(studentas& s1, studentas& s2);
bool isBelowMedian(const studentas& stud);
bool isBelowAverage(const studentas& stud);
string generateRandomName(vector <string> names);
string generateRandomSurname(vector <string> surnames);
void GenerateFile (int kiekis, int nd_kiekis, string &fileName);
/*void test_Vector();
void print_check(const char* desc, const char* expected, const char* actual);
void print_check(const char* desc, int expected, int actual);
void print_check(const char* desc, const void* expected, const void* actual);*/
#endif