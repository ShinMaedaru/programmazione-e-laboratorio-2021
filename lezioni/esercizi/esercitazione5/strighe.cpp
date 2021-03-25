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

//funzione che cerca la lunghezza
//inizalizzo una stringa con le graffe cosi è vuoot
//confronto se la pos è sopra la grandezza ritorno la stringa vuota 
//Se non super la posizione {
//scorro con un ciclo 
//cicolo che dura quante volte è la posizione volte che manda avanti il puntatore il limite è la posizione 
//parto dalla posizione 5 faccio un ciclo da 5 volte che fa lista ->next
//una volta scorsa faccio un ciclo che prende la stringa stringa == se stessa + aggiunta 
//controlla dentro a for se il puntatore non punta a nulla 
//ciclo for in cui fa la somma fa la somma e prima di passare al prossimo iterazione l'if contrlla che non punti a null
//se non punta a null il ciclo continua il second ciclo ha come limite la len 
//}
//se la posizione va oltre il null faccio un controllo che se non mi trovo in null allora fai somma 
int lunghezza(Lista l){
    int count = 0;
    while(l){
        count++;
        Lista temp = l;
        l = l->next;
        delete(temp);
    }
    return count;
}

string concat(Lista l, int pos, int len) {
   
    
}
    

int main() {
  Lista l = nullptr;
  int da, quanti;

  leggi(l);

  std::cin>>da;
  std::cin>>quanti;

  std::cout<<concat(l, da, quanti);

  distruggi(l);

  return 0;
}


