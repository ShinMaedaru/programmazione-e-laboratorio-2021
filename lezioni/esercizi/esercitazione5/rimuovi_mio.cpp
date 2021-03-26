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




void rimuovi_elemento(Listadl& pt, Listadl& pc, int e) {
    int i=0;
    Listadl temp;
    Listadl temp2=pt;
    while(temp2){
        i++;
        //se info è uguale ad e 
        if(temp2->info ==e){
            //casistica: testa
          if(temp2->prev == nullptr && temp2->next != nullptr){
                temp = temp2;
                temp2 ->next->prev =nullptr;
                pt = temp2->next;
                temp2 = temp2->next;
                delete(temp);
            }
            //casistica in mezzo
          else if(temp2->prev != nullptr && temp2->next != nullptr){
                temp = temp2;
                temp2->next->prev =temp2->prev;
                temp2->prev->next =temp2->next;
                temp2=temp2->next;
                delete(temp);
            }
            //casistica coda
            else if(temp2->next == nullptr && temp2->prev != nullptr){
                temp = temp2;
                pc = temp2->prev;
                temp2->prev->next =nullptr;
                temp2=temp2->next;
                delete(temp);
            }
            //casistica un elemento
            else if(temp2->next == nullptr && temp2->prev == nullptr){
                delete(temp2);
                pt = pc=nullptr;
            }
        }
        //se info non è uguale ad e
        else{
            temp2=temp2->next;
        }
    }
}

int main() {
  Listadl pt{nullptr}, pc{nullptr};
  leggi_lista(pt, pc);

  int find;
  std::cin>>find;

  rimuovi_elemento(pt, pc, find);

  stampa_avanti(pt);
  stampa_indietro(pc);

  distruggi_lista(pt);

  return 0;
}