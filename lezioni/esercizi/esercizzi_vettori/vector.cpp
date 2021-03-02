#include <vector>
#include <iostream>
using std::vector;
//legge vettore di interi da tastiera
//termina lettura quando vengono inseriti
//due numeri uguali consecutivi 
//i due numeri uguali non devono comparire nel vettore


//primo modo
void leggi_vettore(vector<int>& vet){//lo voglio modificare
    int prev,cur;
    vet.resize(0);//cancello tutti gli elementi
    std::cin>>cur;
    do{

        prev = cur;
        std::cin>>cur;
        vet.push_back(prev);
        }while (prev!=cur);
    vet.pop_back(); //rimuovi ultimo elemento
}

//secondo modo
vector<int> leggi_vettore2(){//lo voglio modificare
    vector<int> vet;//variabile 
    int prev,cur;
    vet.resize(0);//cancello tutti gli elementi
    std::cin>>cur;
    do{

        prev = cur;
        std::cin>>cur;
        vet.push_back(prev);
        }while (prev!=cur);
    vet.pop_back(); //rimuovi ultimo elemento
    return vet; //ritorno variabile
}

void stampa_vet(vector<int>& v){
    for(int i:v){
        std::cout<<i<< " ";
    }
}

vector<int> solo_pari(const vector<int>& vin){
    
}

int main(){

    vector<int> v;
    vector<int> v2;

    leggi_vettore(v);
    v2 = leggi_vettore2();
    stampa_vet(v);    

    return 0;
}