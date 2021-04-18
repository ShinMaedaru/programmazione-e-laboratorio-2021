#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int average_temperature(istream& is);

class Tempo{//CLASSE: per contenere delle misure temporali
   
    public:
    Tempo(){};//costruttore vuoto 

    void set(string s){//metodo a cui viene dato in pasto una stringa e viene scompattata nelle variabili temporali
        istringstream ss{s}; 
        string temp;
        getline(ss,temp,'/'); giorno = stoi(temp);        
        getline(ss,temp,'/'); mese = stoi(temp);
        getline(ss,temp,'-'); anno = stoi(temp);
        getline(ss,temp,':'); ora = stoi(temp);
        getline(ss,temp,':'); minuti = stoi(temp);
        getline(ss,temp,':'); secondi = stoi(temp);
   };
   //metodi per ricavarsi le variabili di una classe Tempo
   int getGiorno(){
       return giorno;
       
   };
   int getMese(){
       return mese;
   };
   int getAnno(){
       return anno;
   };
   int getOra(){
       return ora;
   };
   int getMinuti(){
       return minuti;
   };
   int getSecondi(){
       return secondi;
   };
   
    private:
    char sep;
    int giorno, mese, anno, ora, minuti, secondi;

};

class Query{ //CLASSE: corrisponde alla prima riga data in input con i parametri giusti
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
    Tempo getTmax(){ //metodo che ritorna il  tempo max
        return tmax;
    };
    Tempo getTmin(){ //metodo che ritorna il tempo min
        return tmin;
    };
    //metodi che ritornano le coordinate della query
    int getLongiMin(){
        return longi_min;
    };
    int getLongiMax(){
        return longi_max;
    }
    int getLatiMin(){
        return lati_min;
    };
    int getLatiMax(){
        return lati_max;
    }; 
    private:
    Tempo tmax;
    Tempo tmin;
    
    int lati_min, lati_max;
    int longi_min,longi_max;
};

//classe che corrisponde alle righe successive alla prima in formato csv  
class Entry{
   
    public: 
    //costruttore vuoto 
    Entry(){};
    //costruttore della entry 
    Entry(const string& ss){
       istringstream s{ss}; 
       string tempo,data;
       char del;
       //la linea fino alla virgola corrisponde al tempo 
       getline(s,tempo,','); 
       time.set(tempo);
       //la getline fino alla graffa corrisponde alle coordinate e temperatura
       getline(s,data,'}');
       //ignoro il carattere seguente che corrisponde alla virgola
       s.ignore();
       //la getline prende la stringa finale che corrisponde alle note
       getline(s,note,'\n');
       //del è un carattere delimitatore che corrisponde alle graffe
       del = data.at(1);
       //stringhe ausiliarie per immagazzinare i dati 
       string aux1,aux2;

       if(del != '['){           
           istringstream s{data};
           s.ignore();
           getline(s,aux1,',');
           temperatura = stoi(aux1);
           s.ignore();
           getline(s,aux2,'}');
           setCoordinate(aux2);
           getline(s,note);

       }else{
           istringstream s{data};
           s.ignore();
           getline(s,aux1,']');
           s.ignore();
           getline(s,aux2,'}');
           temperatura = stoi(aux2);
           setCoordinate(aux1);
           
       }
               
};
    //metodo che setta le coordinate di una entry data una string
    void setCoordinate(const string& ss){
        char del;
        string temp;
        istringstream s{ss}; 
        del = ss.at(0);
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
    };
    Tempo getTime(){
        return time;
    };
    //metodi getter per ottenere le informazioni necessarie 
    int getTemperatura(){
        return temperatura;
    };
    int getLongitudine(){
        return longitudine;
    };
    int getLatitudine(){
        return latitudine;
    };
    string getNote(){
        return note;
    };
    private:
    Tempo time;
    int latitudine, longitudine;
    int temperatura;
    string note; 
};

/*
funzione che confronta le variabili temporali e ritorna true se t è compreso tra 
min e max altrimenti ritorna false
 */
bool check_time(Tempo min,Tempo max,Tempo t){
    bool result = true;
    
    result = t.getAnno() >=min.getAnno() && t.getAnno() <= max.getAnno() ? result : false;
    if(t.getAnno() == min.getAnno()){
        result = t.getMese() >=min.getMese() ? result :false;
        if (t.getMese() ==min.getMese()){
            result = t.getGiorno() >= min.getGiorno() ? result : false;
            if(t.getGiorno() == min.getGiorno()){
                result = t.getOra() >= min.getOra() ? result :false;
                if(t.getOra() == min.getOra()){
                    result = t.getMinuti() >= min.getMinuti() ? result :false;
                    if(t.getMinuti() == min.getMinuti()){
                        result = t.getSecondi() >= min.getSecondi() ? result : false;
                    }
                }
            }          
        }
    }
    if(t.getAnno() == max.getAnno()){
        result = t.getMese() <=max.getMese() ? result :false;
        if (t.getMese() ==max.getMese()){
            result = t.getGiorno() <= max.getGiorno() ? result : false;
            if(t.getGiorno() == max.getGiorno()){
                result = t.getOra() <= max.getOra() ? result :false;
                if(t.getOra() == max.getOra()){
                    result = t.getMinuti() <=max.getMinuti() ? result :false;
                    if(t.getMinuti() == max.getMinuti()){
                        result = t.getSecondi() <=  max.getSecondi() ? result : false;
                    }
                }
            }
        }
    }
   return result;
    
};

//funzione che controlla se le cordinate di una entry sono nei range di una query
bool checkCoordinate(Query& q,Entry& e){
    if(e.getLongitudine()>=q.getLongiMin() && e.getLongitudine()<= q.getLongiMax()){        
        if(e.getLatitudine()>=q.getLatiMin() && e.getLatitudine()<= q.getLatiMax()){
            return true;
        }else{
            return false;
        }
    }else{
         return false;         
    }
    
};

//funzione principale
int average_temperature(istream& is){
    string temp;
    
    getline(is,temp);
    Query query(temp);
    int conta =0;
    int media=0;
    while(!is.eof()){
    getline(is,temp);
    Entry entry(temp); 
    if(entry.getNote()=="accept"){
       if(check_time(query.getTmin(), query.getTmax(), entry.getTime())){
            if(checkCoordinate(query,entry)){
               media = media+entry.getTemperatura();
               conta++;
            }
        }
            
    } 
    }
    if (media==0){ 
     return media;
        
    }else{
    return media/conta;
    }
    
};

int main(){
	cout << average_temperature(cin);
}