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

void cancellaElemento(Lista& precedente,Lista& successivo){
    if(precedente->info == successivo->info){
        precedente->next = successivo->next;
        delete successivo;
    }
}

void elimina_dup(Lista& l)
{
    
}

int main() {
    Lista l = new Cella();
    l->info = 4;
    l->next = nullptr;
    Lista l2 = new Cella();
    l2->info = 2;
    l2->next = l;
    Lista l3 = new Cella();
    l3->info = 2;
    l3->next = l2;
    cancellaElemento(l3,l2);
    stampa_lista(l3);
    distruggi(l);
    return 0;
}