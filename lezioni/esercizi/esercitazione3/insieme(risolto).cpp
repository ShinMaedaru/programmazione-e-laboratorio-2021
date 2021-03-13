#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;

class Insieme{
    private:
    vector<int> myv;

    void sort();
    
    public:
    Insieme() {}
    
    bool appartiene(int elem) const{
        bool answer = false;
        
        for (int e: myv)
            if (e==elem)
                answer= true;
        
        return answer;
    }
    
    
    void aggiungi(int elem) {
        if (!appartiene(elem))
            myv.push_back(elem);
    }
    
    void leggi() {
        int card;
        myv = {};
        cin >> card;
        
        for (int i=0; i<card; i++) {
            int elem;
            cin>>elem;
            aggiungi(elem);
        }
    }

    void stampa() const;

    Insieme intersezione(const Insieme& a) const;

    Insieme unione(const Insieme& a) const; 


    
};

void rimuoviDoppi(vector<int>& v){
    /*funzione che chiede un array ordinato e
    restituisce al post dell'originale
    un nuovo array senza i doppioni.*/         
    int j=0;
    int n = v.size();
    vector<int> res;
     if (n==0){
         v = res;    
    }else{
    res.push_back(v.at(j));
    for (int i=1;i<n;++i){
     if (v.at(j) != v.at(i)){
          ++j;
          v.at(j) = v.at(i);
         res.push_back(v.at(j));
     }
    }   
}
    v = res;
}

void Insieme::sort(){ 
//metodo basato sulla funzione bubble sort vista a lezione
   int temp;
   int n = myv.size();
    for (int i = 0; i < n-1; i++) {
      for (int j = i+1; j < n; j++) {
         if (myv.at(i) > myv.at(j)) {
            temp = myv.at(i);
            myv.at(i) = myv.at(j);
            myv.at(j) = temp;
         }
      }
   }
}

void Insieme::stampa() const{
    //metodo che riordina,rimuove ii duplicati e stampa un'array(insieme)
    
    Insieme r;//non ho capito come richiamare sort sull'istanza attuale quindi faccio un nuovo insieme
    r.myv = myv;
    r.sort();
    //vector<int> res =
    rimuoviDoppi(r.myv);
    for(int i:r.myv){
        cout<<i<<std::endl;
    }
};

Insieme Insieme::intersezione(const Insieme &a) const{
    //metodo che restituisce un nuovo insieme il cui vettore
    //è composto dagli elementi comuni dei 2 vettori(chaiamnte,parametro funzione)
    //siccome si usa un doppio ciclo for ci saranno dei duplicati che verranno eliminati dalla funzione stampa
    Insieme res;  
    int n = myv.size();
    int m = a.myv.size();
    for (int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(myv.at(i)==a.myv.at(j)){
                res.myv.push_back(myv.at(i)); 
            }
        }
    }
    
    return res;
};

Insieme Insieme::unione(const Insieme &a) const{
    //metodo che restituisce un nuovo insieme il cui vettore
    //è composto dal vettore del chiamante più il parametro della funzione
    Insieme res;
    res.myv = myv;
    for(int i:a.myv){
        res.myv.push_back(i);
    }
    return res; 
};


/*implementa le funzioni stampa, intersezione, unione e sort!*/
int main() {
    Insieme a;
    Insieme b;
    Insieme i, u;
    
    a.leggi();
    b.leggi();

    i = a.intersezione(b);
    u = a.unione(b);
    
    cout<<"Intersezione:"<<std::endl;
    i.stampa();
    cout<<"Unione:"<<std::endl;
    u.stampa();

    return 0;
}