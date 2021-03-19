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
void reverse(Lista &l){
    Lista prev = new Cella();
    Lista curr = new Cella();
    Lista next = new Cella();
    prev = nullptr;
    curr = next = l;
    while(next!=0){
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l = prev;
}
//Lista somma_acc(const Lista& l) {}

int main() {
    Lista l = nullptr;
    //leggi(l);
    append(l,1);
    append(l,2);
    append(l,3);
    append(l,4);
    append(l,5);
    reverse(l);
    //Lista ris = somma_acc(l);
    stampa_lista(l);
    distruggi(l);
    //distruggi(ris);
    return 0;
}