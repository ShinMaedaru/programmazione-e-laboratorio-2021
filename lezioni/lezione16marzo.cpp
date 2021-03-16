#include<iostream>
#include<vector>
using std::vector;

void foo(vector<int> a){//passaggio per copi
a.at(0) =13;//modifica la mia copia ma non il vettore chiamante

}

void foo1(vector<int>& a){//passaggio per reference
a.at(0) =13; //modifica il mio vettore che corrisponde al chiamante

}

void foo3(vector<int>* pvect){ //con i puntatori
    pvect->at(0)= 13;
}

int main(){
    vector<int> x;
    foo(x);
    foo1(x);
    vector<int> *y = new vector<int>;
    foo3(y);
    delete y;
    return 0;
}