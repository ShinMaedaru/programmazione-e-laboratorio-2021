#include<iostream>
#include<string>

using std::string;

struct Cella{
  string info;
  Cella* next;
};

typedef Cella* Lista;

void prepend(Lista& l, const string& s) {
  Lista nuova = new Cella;

  nuova->next=l;
  nuova->info = s;
  l=nuova;
}


void append(Lista& l, const string& s) {
  if (!l)
    prepend(l, s);
  else
    append(l->next, s);
}

void leggi(Lista& l) {
  int e;
  std::cin>>e;

  while (e>0) {
    string buffer;
    std::cin>>buffer;
    append(l, buffer);
    e--;
  }
}

void distruggi(Lista& l) {
  if (l) {
    distruggi(l->next);
    delete l;
    l=nullptr;
  }
}


//funzione ausiliaria che restituisce la lunghezza della lista
int lunghezza(Lista l){
    int count = 0;
    while(l){
        count++;
        l = l->next;
    }
    return count;
} 
string concat(Lista l, int pos, int len) {
    //inserisco la lunghezza in una variabile 
    int n = lunghezza(l);
    //inizializzo una stringa vuota
    string res="";
    /*se la posizione in input è più grande 
    della grandezza effettiva della lista
    ritorna res che è inizilizzata come vuota
    */
    if(pos>n){
        return res;
    }else{
    //CASISTICA: pos è nella grandezza 
     for(int i=0;i<pos;i++){         
    /*ciclo fino alla pos in input e sposto 
    l fino a quella pos
    */
         l = l ->next;
     }

    for(int j = 0;j<len;j++){
        //ciclo fino alla len in input
        //se non ho raggiunto la fine della lista:
        if(l!=nullptr){
            //sommo la stringa e sposto l
            res = res+l->info;
            l = l->next;
        }
        /*se ho raggiunto la fine della lista:
        non sommo e non sposto niente per evitare 
        seg fault*/
    }
    //ritorno la stringa sommata
    return res;
}   
}


int main() {
  Lista l = nullptr;
  int da, quanti;
/*
5
questa
e
una
prova
!
3
2*/
  leggi(l);

  std::cin>>da;
  std::cin>>quanti;

  std::cout<<concat(l, da, quanti);

  distruggi(l);

  return 0;
}


