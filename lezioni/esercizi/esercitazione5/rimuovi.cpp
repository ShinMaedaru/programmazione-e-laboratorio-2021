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

  if(pt){
        //casistica: il penultimo elemento è uguale ad e 
        if(pt->next == pc){
            //se il contenuto della coda è uguale ad e:
            if(pc->info == e){                    
                Listadl temp = pc;
                pc->prev->next = nullptr;
                pc=pc->prev;
                delete(temp);
                //ricomincio la ricorsione perchè manca ancora l'ultimo elemento
                rimuovi_elemento(pt,pc,e);  
            }
        } 
        //casistica: la coda non è nulla

        if(pt->next != nullptr){
            //l'elemento attuale della testa è uguale ad e 
            if(pt->info == e){

                //se prev è uguale a nullptr vuol dire che sono nella testa
               //CASISTICA FUNZIONANTE
                if(pt->prev == nullptr){
                    Listadl temp = pt;
                    pt = pt->next;
                    pt->prev = nullptr;
                    delete(temp);
                    //ricomincio la ricorsione perchè devo controllare il resto della lista 
                    rimuovi_elemento(pt,pc,e);  
                //nel caso l'elemento da rimuovere sia nel mezzo tra due nodi

                //CASISTICA FUNZIONANTE(?)

                }else{     
                    Listadl temp = pt;
                    pt->next->prev = pt->prev;
                    pt=pt->next;
                    delete(temp);
                    rimuovi_elemento(pt,pc,e);  
                }
            }
            //nel caso l'info in testa non sia uguale ad e allora 
            //ricomincio la ricorsione
            rimuovi_elemento(pt->next,pc,e);  
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