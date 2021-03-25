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

void aggiungi(Cella* prima,int nuovo){
    Cella* nuova_cella = new Cella();
    nuova_cella->info = nuovo;
    nuova_cella->next = prima->next;
    prima->next = nuova_cella;
}

void duplica(Lista& l)
{
   if(l){

      Cella* temp = new Cella();
      temp->next = l->next;
      aggiungi(l->next,l->info);
      duplica(temp->next);
   }
}


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
int main() {
    Lista l = nullptr;
    prepend(l,1);
    prepend(l,2);
    prepend(l,2);
    prepend(l,3);
    duplica(l);
   // leggi(l);
    std::cout<<lunghezza(l)<<std::endl;  
    stampa_lista(l);
    distruggi(l);
    return 0;
}