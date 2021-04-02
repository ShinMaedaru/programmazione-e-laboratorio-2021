#include<iostream>

struct Cella_circ{
  int info;
  struct Cella_circ* next;
};


typedef Cella_circ* Lista_circ;


//aggiunta in testa alla lista
void add(Lista_circ& lista, int x) {
  Lista_circ nuovo = new Cella_circ;
  nuovo->info = x;
  if (lista==nullptr) {
    nuovo->next = nuovo;
    lista = nuovo;
  }
  else {
    nuovo->next = lista->next;
    lista->next = nuovo;
  }
}

//stampa lista
void stampa_lista(Lista_circ l) {
  if (l) {
    Lista_circ pc{l};
    do {
      std::cout<<l->info << " ";
      l=l->next;
    } while (l!=pc);
  }
  std::cout<<std::endl;
}


//distruggi lista
void distruggi(Lista_circ& l) {
  if (l) {  
    Lista_circ supp, sentinella{l};
    do {
      supp = l;
      l=l->next;
      delete supp;
    } while (l!=sentinella);
    l = nullptr;
  }
}


//leggi lista
void leggi_lista(Lista_circ& l) {
  int elem, n;
  std::cin>>n;
  while (n>0) {
    std::cin>>elem;
    add(l, elem);
    n--;
  }
}


int Lunghezza(Lista_circ l){
    int count =0;
    if(l){
        Lista_circ testa{l};
        
        do{
            l=l->next;
            count++;
        }while(l!=testa);
    }
    return count;
}
bool tutti_positivi(Lista_circ l) {
    //std::cout<<"/////////////////////"<<std::endl;
    //stampa_lista(l);
    //std::cout<<"/////////////////////"<<std::endl;

   bool temp = true;
   int n = Lunghezza(l);
    if (l) {
    Lista_circ pc{l};
    do {
      if (l->info<=0){
          temp = false;
      }
      l=l->next;
    } while (l!=pc);
    return temp;
  }else{
      return true;
  }
}


int main() {

  int elimina;
  Lista_circ l=nullptr;

  leggi_lista(l);

  if (tutti_positivi(l)) 
    std::cout<<"Tutti gli elementi sono positivi";
  else
    std::cout<<"Almeno un elemento e' negativo o nullo";


  distruggi(l);
  return 0;
}

