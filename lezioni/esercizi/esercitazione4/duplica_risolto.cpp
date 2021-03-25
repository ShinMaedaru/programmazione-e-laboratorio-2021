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

void inserisci(Lista& precedente,Lista& successivo,Lista& aggiunto){
    if(precedente->next == successivo){
        aggiunto->next = successivo;
        precedente->next = aggiunto;
    }
}

void duplica(Lista& l)
{
    //se la lista ha almeno un elemento
    if(l){
    //se la lista ha un solo elemento faccio un append
    if(l->next == nullptr){
    append(l,l->info);
    }
    else{
        //creo una nuova cella di supporto
        Lista nuovo = new Cella();
        //il supporto prende il valore corrente
        nuovo->info = l->info;
        //il supporto punta a nullo
        nuovo->next = nullptr;
        //in mezzo all'elemento di testa e di coda metto il supporto
        inserisci(l,l->next,nuovo);
        
        //siccome il supporto diventa la coda itero sul next del supporto
     duplica(nuovo->next);
    }
  }
}
void duplica2(Lista& l){

    if(l){
        if(l->next == nullptr){
            append(l,l->info);     
        }

    for(Lista iter = l; iter != nullptr && iter->next != nullptr; iter = iter->next){ 
        
        Lista nuovo = new Cella();
        //il supporto prende il valore corrente
        nuovo->info = iter->info;
        //il supporto punta a nullo
        nuovo->next = nullptr;
        inserisci(iter,iter->next,nuovo);
        iter->next =nuovo->next;
        
    }
    }
}

int lunghezza(Lista l){
    int count = 0;
    while(l){
        count++;
        l = l->next;
    }
    return count;
}

int main() {
    Lista l = nullptr;
    append(l,1);
    append(l,2);
    append(l,4);
    duplica(l);
    
    stampa_lista(l);
    std::cout<<std::endl;
    std::cout<<"lunghezza della lista: "<<lunghezza(l)<<std::endl;  

    distruggi(l);
    return 0;
}