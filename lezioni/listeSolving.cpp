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

int elimina_coda(Lista& l ,int n){
    if(l == nullptr){
        return 0;
    }
    else{//next esiste sempre perchè abbiamo definito il caso base
        int m = elimina_coda(l->next,n);
        if(m<n){//caso cella singola
            delete l;
            l=nullptr;
            return m+1;
        }else{
            return m; 
        }
    }
}
int elimina_testa(Lista& l,int n){
    if(l==nullptr|| n==0){
        return 0;
    }
    else{
        Lista supp = l;
        l = l->next;
        delete supp;
        int m = elimina_testa(l,n-1);
        return n+1;
        
    }
}
int main() {
    Lista l = nullptr;
    append(l,1);
    append(l,1);
    append(l,3);
    append(l,4);
    append(l,5);
    append(l,6);
    append(l,7);
    elimina_coda(l,3);
    stampa_lista(l);
    distruggi(l);
    return 0;
}