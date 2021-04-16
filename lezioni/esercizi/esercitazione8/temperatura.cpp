#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int average_temperature(istream& is);
class Tempo{
    private:
    int giorno, mese, anno, ora, minuti, secondi;
    char sep;
    public:
    Tempo(){};
     
    void set(string s)
    {
        istringstream ss{s}; 
        string temp;
        getline(ss,temp,'/'); giorno = stoi(temp);        
        getline(ss,temp,'/'); mese = stoi(temp);
        getline(ss,temp,'-'); anno = stoi(temp);
        getline(ss,temp,':'); ora = stoi(temp);
        getline(ss,temp,':'); minuti = stoi(temp);
        getline(ss,temp,':'); secondi = stoi(temp);
   }
   
   void print(){
       cout<<giorno<<" "<<mese<<" "<<anno<<" "<<ora<<" "
       <<minuti<<" "<<secondi<<" "<<std::endl;
   }
};


class Query{
    private:
    Tempo tmax;
    Tempo tmin;
    
    int latitudine_min, latitudine_max;
    int longi_min,longi_max;
    public:
     Query(const string& s){
       istringstream ss{s}; 
       string temp;
       getline(ss,temp,','); tmin.set(temp);   
       getline(ss,temp,','); tmax.set(temp);
       getline(ss,temp,','); latitudine_min = stoi(temp);
       getline(ss,temp,','); latitudine_max = stoi(temp);
       getline(ss,temp,','); longi_min = stoi(temp);
       getline(ss,temp,','); longi_max = stoi(temp);

     }; 
     
     void printQuery(){
         
         tmin.print();
         tmax.print();
        cout<<latitudine_min<<" "<<latitudine_max << " "<< longi_min << " "<< longi_max<<std::endl;

    };
    
};

class Entry{
    private:
    Tempo time;
    int latitudine, longitudine;
    int temperatura;
    string note; 
    public: 
    Entry(const string& s){
       istringstream ss{s}; 
       string temp;
       getline(ss,temp,','); time.set(temp);
       
    };
    void printEntry(){
        time.print();
    }
};


void read_time(istream&){
    
}
int average_temperature(istream& is){
    string temp;
    getline(is,temp);
    Query prova(temp);
    getline(is,temp);
    Entry n1(temp);
    
    cout<<"///////////////"<<std::endl;
    prova.printQuery();
     cout<<"///////////////"<<std::endl;

    n1.printEntry();    
  
    cout<<"///////////////"<<std::endl;
    return 0;
}

int main(){
	cout << average_temperature(cin);
}