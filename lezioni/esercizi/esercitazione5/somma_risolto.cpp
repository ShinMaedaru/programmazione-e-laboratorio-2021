#include<iostream>


struct Celladl{
  int info;
  Celladl* next;
  Celladl* prev;
};

typedef Celladl* Listadl;

void append(Listadl& pt, Listadl& pc, int info) {
  Listadl nuova = new Celladl;
  nuova->next = nullptr;
  nuova->prev = pc;
  nuova->info = info;

  if (pc) 
    pc->next = nuova;

  if (!pt) 
    pt = nuova;

  pc = nuova;

}

void stampa_avanti(Listadl pt) {
  while (pt) {
    std::cout<<pt->info<<" ";
    pt = pt->next;
  }
  std::cout << std::endl;
}


void stampa_indietro(Listadl pc) {
  while (pc) {
    std::cout << pc->info <<" ";
    pc = pc->prev;
  }
  std::cout << std::endl;
}


void leggi_lista(Listadl& pt, Listadl& pc) {
   int elements;
   std::cin >> elements;

   while (elements>0) {
     int info;
     std::cin>>info;
     append(pt, pc, info);
     elements--;
   }
}

void distruggi_lista(Listadl& pt) {
  Listadl supp;
  while(pt) {
    supp = pt;
    pt = pt->next;
    delete supp;
  }
  pt = nullptr;
}


int lunghezza(Listadl l){
    int count = 0;
    while(l){
        count++;
        l = l->next;
    }
    return count;
} 


int somma(Listadl pt, int v) {
    int temp = -1;
    int n = lunghezza(pt); 
    
    while(pt){   
    if(pt->info == v){
    //casistica: la lista ha un solo elemento
    if(n ==1){
        temp = v;
    }else{
        //casistica: testa
        if(pt->prev == nullptr){
        temp = v;
        temp += pt->next->info;
      }
      //casistica coda
      if(pt->next == nullptr){
          temp = v;
          temp += pt->prev->info;
      }
    //casistica: mezzo     
      if(pt->next !=nullptr && pt->prev!=nullptr){
          temp = v;
          temp += pt->prev->info;
          temp += pt->next->info;
      }
    
    } 
    }     
      pt=pt->next;
    }
    distruggi_lista(pt);
    return temp;
}
int main() {
  Listadl pt{nullptr}, pc{nullptr};
  leggi_lista(pt, pc);

  int find;
  std::cin>>find;

  std::cout << somma(pt, find); 

  distruggi_lista(pt);

  return 0;
}