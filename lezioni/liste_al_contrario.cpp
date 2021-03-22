#include <iostream>

struct Cella{
  int info;
  struct Cella* next;
};


typedef struct Cella* Lista;


//aggiunta in testa alla lista
void prepend(Lista& lista, int x) {
  Lista nuovo = new Cella;
  nuovo->info = x;
  nuovo->next = lista;
  lista = nuovo;
}

//aggiunta in coda alla lista
void append(Lista& l, int data) {
  if (!l)            
    l = new Cella{data, nullptr};
  else append(l->next, data);
}

//stampa lista
void stampa_lista(Lista l) {
  if (l) {
    std::cout<<l->info<<std::endl;
    stampa_lista(l->next);
  }
}

//distruggi lista
void distruggi(Lista& l) {
  Lista supp;
  while(l) {
    supp = l;
    l = l->next;
    delete supp;
  }
}

void leggi(Lista& l) {
    distruggi(l);
    int elem;
    std::cin>>elem;
    
    while (elem > 0) {
        int e;
        std::cin >> e;
        append(l, e);
        elem--;
    }
}

void stampa(Lista& l){
    while(l){
        std::cout<<l->info<<std::endl;
        Lista temp = l;
        l = l->next;
        delete temp;
    }
}
void stampa_ricorsiva(Lista& l){
    if(l){
        std::cout<<l->info<<" ";
        stampa_ricorsiva(l->next);
    }
}
//funzione che stampa al contrario una lista
void traverse(Lista& n) {
		if(n){ 
         /*
         (2) faccio partire la ricorsione
         prima dell'azione della funzione in modo
         tale che raggiunga il caso base del termine lista/vuota
          e poi a cascata faccia l'azione in questione
          */    
		traverse(n->next);
        //(3)eseguo l'azione della funzione
        std::cout<<n->info<<" ";
        }//(1) caso base lista vuota non entra nell'if
	}

int main() {
    Lista l = nullptr;
    append(l,1);
    append(l,2);
    append(l,3);
    append(l,4);
    append(l,5);
    stampa_ricorsiva(l);
    std::cout<<std::endl;
    traverse(l);
    distruggi(l);
    return 0;
}