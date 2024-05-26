#include "../headers/main.h"
#include "../headers/function.h"
int number1,skaicius,n,m;  
vector<string> names;
vector<string> surnames;
Vector <studentas> s; //studentai
int main() 
{
  try{
  auto start=chrono::high_resolution_clock::now();
  srand(time(0));
  string duomPav;
  Vector <studentas> s; //studentai
  Vector <studentas> k; //kieti s
  Vector <studentas> l; //lievi s
  
  srand(time(nullptr));
        //test
        // Pradėti v1 užpildymo laiko matavimą
        auto start1 = chrono::high_resolution_clock::now();
unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000
int v1p=0,v2p=0;
std::vector<int> v1;
for (unsigned int i = 1; i <= sz; ++i)
  {v1.push_back(i);
  if(v1.size()==v1.capacity())
  v1p++;
  }
// Baigti v1 užpildymo laiko matavimą
auto end1 = chrono::high_resolution_clock::now();
auto duration1 = chrono::duration_cast<chrono::microseconds>(end1-start1).count();
cout<<"std::vector uzpildymas truko: "<<duration1/1000.0<<" milisekundes"<<endl;
// Pradėti v2 užpildymo laiko matavimą
auto start2 = chrono::high_resolution_clock::now();
Vector<int> v2;
for (unsigned int i = 1; i <= sz; ++i)
  {v2.push_back(i);
  if(v2.size()==v2.capacity())
  v2p++;
  }
// Baigti v2 užpildymo laiko matavimą 
auto end2 = chrono::high_resolution_clock::now();
auto duration2 = chrono::duration_cast<chrono::microseconds>(end2-start2).count();
cout<<"Vector uzpildymas truko: "<<duration2/1000.0<<" milisekundes"<<endl;
cout<<"std::vector realokacijos: "<<v1p<<endl;
cout<<"Vector realokacijos: "<<v2p<<endl;
        //zmogus zm;
        /*
        studentas studentas1("Gytis", "Malinauskas");
        studentas studentas2("Vardas", "Pavardaitis");
        studentas2.setND(10);
        studentas2.setEgz(5);
        studentas2.setMed(9);
        cout << studentas1 << endl;
        cout << studentas2 << endl;
        studentas studentas3(studentas1);
        cout << studentas3 << endl;
        studentas studentas4(std::move(studentas2));
        cout << studentas4 << endl;
        studentas studentas5;
        studentas5 = studentas1;
        studentas studentas6;
        studentas6 = std::move(studentas4);
        ofstream output("test.txt");
        output << studentas1 << endl;
        output << studentas2 << endl;
        output << studentas3 << endl;
        output << studentas4 << endl;
        output << studentas5 << endl;
        output << studentas6 << endl;
        output.close();
*/

  while (true)
  {
  cout<<"Enter number"<<endl; 
  cout<<"1 - manual input"<<endl;
  cout<<"2 - generate grades"<<endl;
  cout<<"3 - generate names and grades"<<endl;
  cout<<"4 - reading from file"<<endl;
  cout<<"5 - generate file"<<endl;
  cout<<"6 - quit / show results"<<endl;
  cout<<"Number: ";
  try{
  skaicius=intIvestis(1,6);}
  catch(const exception &e)
  {cerr<<"Klaida: "<<e.what()<<endl;
  continue;}
  cout<<endl;
  if(skaicius==6)
  {break;}
  if(skaicius==3)
  {
    VarduGeneravimui();
  }
  if(skaicius!=4 && skaicius!=5){
  cout<<"Enter number"<<endl;
  cout<<"1 - n and m is given"<<endl;
  cout<<"2 - n and m is not given"<<endl;
  cout<<"Number: ";
 
  number1=intIvestis(1,2);
  cout<<endl;
  if(number1==1){
  cout<<"Enter the number of students: "; m=intIvestis2();
  cout<<"Enter the number of homework: "; n=intIvestis2();
  }
      studentas st;
      if(number1==1){
      for(int i=0; i<m; i++){
      cin>>st;
      s.push_back(std::move(st));}
      }
      if(number1==2){
      while(true){
      cin>>st;
      if(st.getName()=="q")
      {break;}st.getName();
      s.push_back(std::move(st));}
      
      }
      names.clear();
      surnames.clear();
      cout<<endl;
  }
  if(skaicius==4)
  {
    FailoSkaitymas(s,duomPav);
      }
  if(skaicius == 5){
            int kiekis;
            int nd_kiekis;
            string fileName;
            cout << "How many students you want to generate in file?: "<<endl
                 << "Number: ";
            kiekis=intIvestis2();
            cout<<endl;
            cout << "How many tasks should students have (final counts in)?: "<<endl
                 <<"Number: "; 
                 nd_kiekis=intIvestis2();
            cout<<endl;
            auto start_generate=chrono::high_resolution_clock::now();
            GenerateFile(kiekis, nd_kiekis,fileName);
            auto end_generate=chrono::high_resolution_clock::now();
            auto duration_generate= chrono::duration_cast<chrono::milliseconds>(end_generate-start_generate).count();  
            cout << "Failo " << fileName << " generavimas uztruko: " << duration_generate/1000.0 << " sekundes" << endl;
        }
    }
    Isvedimas(s,l,k);
    auto end =chrono::high_resolution_clock::now();
    auto duration_start_to_end= chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << "Visos programos veikimas uztruko: " << duration_start_to_end/1000.0 << " sekundes" << endl;
    return 0;
  }
  catch(const exception& e){
                cerr << "Klaida: " << e.what() << endl;
                return 1;
            }
  
}