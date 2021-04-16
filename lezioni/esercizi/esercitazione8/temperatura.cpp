#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int average_temperature(istream& is);

//classe per il tempo 
class Tempo{
    private:
    char sep;
    public:
    //costruttore vuoto 
    Tempo(){};
    //le variabili sono dichiarate public cosi non devo creare troppi metodi getter
    int giorno, mese, anno, ora, minuti, secondi;
    //metodo a cui viene dato in pasto una stringa e viene scompattata nelle variabili temporali
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

//classe che corrisponde alla prima riga data in input con i parametri giusti
class Query{
    private:
    Tempo tmax;
    Tempo tmin;
    
    int lati_min, lati_max;
    int longi_min,longi_max;
    public:
    //costruttore che prende una stringa e la scompatta in base alle variabili
     Query(const string& s){
       istringstream ss{s}; 
       string temp;
       getline(ss,temp,','); tmin.set(temp);   
       getline(ss,temp,','); tmax.set(temp);
       getline(ss,temp,','); lati_min = stoi(temp);
       getline(ss,temp,','); lati_max = stoi(temp);
       getline(ss,temp,','); longi_min = stoi(temp);
       getline(ss,temp,','); longi_max = stoi(temp);

     }; 
     
     void printQuery(){
         
         tmin.print();
         tmax.print();
        cout<<lati_min<<" "<<lati_max << " "<< longi_min << " "<< longi_max<<std::endl;

    };
    Tempo getTmax(){ //metodo che ritorna il tempo max
        return tmax;
    };
    Tempo getTmin(){ //metodo che ritorna il tempo min
        return tmin;
    };
    int getLongiMin(){
        return longi_min;
    }
    int getLongiMax(){
        return longi_max;
    }
    int getLatiMin(){
        return lati_min;
    }
    int getLatiMax(){
        return lati_max;
    }    
};
//classe che corrisponde alle righe successive alla prima in formato csv  
class Entry{
    private:
    Tempo time;
    int latitudine, longitudine;
    int temperatura;
    string note; 
    public: 
    //metodo che setta le coordinate della entry nelle variabili
    void setCoordinate(const string& ss){
        char del;
        string temp;
        istringstream s{ss}; 
        del = ss.at(0);
        //cout<<"del :"<<del<<endl;

        if(del !='['){
            getline(s,temp,','); 
            latitudine = stoi(temp);
            getline(s,temp,']'); 
            longitudine = stoi(temp);
            
        }
        else{
            s.ignore();
            getline(s,temp,',');
            latitudine = stoi(temp);
            getline(s,temp);
            longitudine = stoi(temp);
            
                        
        }
    }
    
    Entry(const string& ss){
       istringstream s{ss}; 
       string tempo,info;
       char del;
       //cout<<ss<<std::endl;
       getline(s,tempo,','); time.set(tempo);
       getline(s,info,'}');
        s.ignore();
       getline(s,note,'\n');
       del = info.at(1);
       //cout<<"vediamo del: "<<del<<endl;
       if(del != '['){
           string str1,str2;
           istringstream s{info};
           s.ignore();
           getline(s,str1,',');
           temperatura = stoi(str1);
           //cout<<"temperatura: "<<temperatura<<endl;

           s.ignore();
           getline(s,str2,'}');
           setCoordinate(str2);
            //cout<<"latitudine :"<<latitudine<<" longitudine: "<< longitudine<<endl;
            getline(s,note);

       }else{
            string str1,str2;
           istringstream s{info};
           s.ignore();
           getline(s,str1,']');
           s.ignore();
           getline(s,str2,'}');
           temperatura = stoi(str2);
           //cout<<"temperatura: "<<temperatura<<endl;
            setCoordinate(str1);
            //cout<<"latitudine :"<<latitudine<<" longitudine: "<< longitudine<<endl;
           
       }
               
    };
    void printEntry(){
        time.print();
    }
    Tempo getTime(){
        return time;
    }
    //metodi getter per ottenere le informazioni necessarie 
    int getTemperatura(){
        return temperatura;
    }
    int getLongitudine(){
        return longitudine;
    }
    int getLatitudine(){
        return latitudine;
    }
    string getNote(){
        return note;
    }
};

/*
funzione che confronta le variabili temporali e ritorna true se t è compreso tra 
min e max altrimenti ritorna false
 */
bool check_time(Tempo min,Tempo max,Tempo t){
    bool result = true;
    
    result = t.anno >=min.anno && t.anno <= max.anno ? result : false;
    if(t.anno == min.anno){
        result = t.mese >=min.mese ? result :false;
        if (t.mese ==min.mese){
            result = t.giorno >= min.giorno ? result : false;
            if(t.giorno == min.giorno){
                result = t.ora >= min.ora ? result :false;
                if(t.ora == min.ora){
                    result = t.minuti >= min.minuti ? result :false;
                    if(t.minuti == min.minuti){
                        result = t.secondi >= min.secondi ? result : false;
                    }
                }
            }
            
        }
        if(result == false){
            return result;
        }
    }
    if(t.anno == max.anno){
        result = t.mese <=max.mese ? result :false;
        if (t.mese ==max.mese){
            result = t.giorno <= max.giorno ? result : false;
            if(t.giorno == max.giorno){
                result = t.ora <= max.ora ? result :false;
                if(t.ora == max.ora){
                    result = t.minuti <=max.minuti ? result :false;
                    if(t.minuti == max.minuti){
                        result = t.secondi <=  max.secondi ? result : false;
                    }
                }
            }
        }
         if(result == false){
            return result;
        }
        
    }
   return result;
    
}
//funziona
bool checkCoordinate(Query q,Entry e){
    if(e.getLongitudine()>=q.getLongiMin() && e.getLongitudine()<= q.getLongiMax()){
        
        if(e.getLatitudine()>=q.getLatiMin() && e.getLatitudine()<= q.getLatiMax()){
            return true;
        }else{
            return false;
        }
    }else{
         return false;         
    }
    
}

int average_temperature(istream& is){
    string temp;
    
    getline(is,temp);
    Query prova(temp);
   // cout<<temp<<std::endl;
    int conta =0;
    int media=0;
    int risultato =0;
   // cout<<"range latitudine min: "<<prova.getLatiMin()<<" max: "<<prova.getLatiMax()<<endl;
   // cout<<"range longitudine min: "<<prova.getLongiMin()<<" max: " <<prova.getLongiMax()<<endl;

    while(is){
   //cout<<"///////////////"<<std::endl;
    getline(is,temp);
    Entry n1(temp); 
    //cout<<temp<<endl;

    
   //cout<<n1.getNote()<<endl; 
  // cout<<"temperatura: "<<n1.getTemperatura()<<endl;
  // cout<<"latitudine :"<<n1.getLatitudine()<<" longitudine: "<< n1.getLongitudine()<<endl;
    if(n1.getNote()=="accept"){
       if(check_time(prova.getTmin(), prova.getTmax(), n1.getTime())){
            if(checkCoordinate(prova,n1)){
               media = media+n1.getTemperatura();
               conta++;
         //cout<<"entry accettata"<<endl;
            }
            }
            
    }
    
    else{
    //cout<<"entri non accettata per reject"<<endl;
    } 
    // cout<<"somma: "<< media<<endl;
    }
   // cout<<"passi: "<< conta<<endl;

    if (media !=0){
      
     return media/conta;
        
    }else{
    return media;
    }}
int main(){
	cout << average_temperature(cin);
}