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
        if (successivo->next != nullptr){
        precedente = successivo->next;    
          
        successivo = nullptr;
        } else{
          precedente = successivo;
        }
}

void elimina_dup(Lista& l){
 if(l){
      if(l->next != nullptr){
        if(l->info ==l->next->info){
          l = l->next;          
          elimina_dup(l);

        }else{
          elimina_dup(l->next);
 
        }

      } 

    }
}

int main() {
    Lista l = nullptr;
    leggi(l);
    elimina_dup(l);
    stampa_lista(l);
    distruggi(l);
    return 0;
}