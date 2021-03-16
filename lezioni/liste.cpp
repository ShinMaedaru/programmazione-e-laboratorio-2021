#include <iostream>

struct Cella{
    
    int info;
    struct Cella* next;
};
//aggiunge in testa 
typedef struct Cella* Lista;
void prepend(Lista& lista,int info){
    Lista nuovo = new Cella;
    nuovo->info = info;
    nuovo ->next = lista;
    lista = nuovo;
}
//void stampalista
void stampa_lista(Lista l){
    if(l){
        std::cout<<l->info<<std::endl;
        stampa_lista(l->next);
    }
}
//distruggere lista
void distruggi(Lista& l){
    Lista supp;
    while(l){//lista che voglio scorrere
        supp = l; //supporto punta dove punta l
        l = l->next;//spingo avanti l di 1 
        //cancello supporto e cancello lo spazio di memoria
        delete supp;
    }
}

void distruggi_ric(Lista& l){
    if(l){
        distruggi_ric(l->next);
        delete l;
    }
}
//aggiunge in coda
void append(Lista& l, int data){
    if(!l){
        l = new Cella{data,nullptr};
    } else{
        append(l->next,data);
    }

}

int massimo(Lista l){
    if(l->next ==nullptr){
        return l->info;
    }else{
        int max = massimo(l->next);
        if (l->info > max){
            return l->info;
        }
        else{
            return max;
        }
    }
}
int main(){
    Lista l = nullptr; //lista vuota
    prepend(l,14);
    return 0;
}