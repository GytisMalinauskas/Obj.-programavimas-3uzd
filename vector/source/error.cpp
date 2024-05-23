#include "../headers/error.h"
int intIvestis(int sRange, int eRange) {
    int cInput;
    
      while (true) {
        try{
        if (!(cin>>cInput)|| cInput < sRange || cInput > eRange) {
            throw runtime_error ("Ivestas netinkamas skaicius arba netinkamai perskaitoma ivestis.");
        }
        return cInput;
        } 
        catch(const runtime_error& e)
        {
          cerr << "Klaida: " << e.what() << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
       
}
}
int intIvestis2() {
    int cInput;
    while (true) {
        try{
        if (!(cin>>cInput)||isdigit(cInput)) {
            throw "Klaida. Netinkamai perskaitoma ivestis arba ivedete ne skaiciaus simboli.";
        }
        return cInput;
        //break;
            }
            catch (char const *error) {
            cerr<< error<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
char SimbolioTikrinimas()
{
    char budas;
    while(true)
    {
        try{
        if(!(cin >> budas) || (budas != 'g' && budas != 'q'))
        {
            throw "Įvestas netinkamas simbolis. Įveskite dar kartą 'v' arba 'm': ";
        }
        return budas;
        //break;
        } catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
char SimbolioTikrinimas2()
{
    char budas;
    while(true)
    {
        try{
        if(!(cin >> budas) || (budas != 'a' && budas != 'm'))
        {
            throw "Įvestas netinkamas simbolis. Įveskite dar kartą 'v' arba 'm': ";
        }
        return budas;
        //break;
        } catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
char SimbolioTikrinimas3()
{
    char budas;
    while(true)
    {
        try{
        if(!(cin >> budas) || (budas != 'f' && budas != 'c'))
        {
            throw "Įvestas netinkamas simbolis. Įveskite dar kartą 'v' arba 'm': ";
        }
        return budas;
        //break;
        } catch (char const *error)
        {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}