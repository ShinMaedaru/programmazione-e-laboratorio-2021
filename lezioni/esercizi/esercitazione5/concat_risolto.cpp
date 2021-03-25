#include<iostream>
#include<string>

using std::string;

struct Cella{
  string info;
  Cella* next;
};

typedef Cella* Lista;

void prepend(Lista& l, const string& s) {
  Lista nuova = new Cella;

  nuova->next=l;
  nuova->info = s;
  l=nuova;
}


void append(Lista& l, const string& s) {
  if (!l)
    prepend(l, s);
  else
    append(l->next, s);
}

void leggi(Lista& l) {
  int e;
  std::cin>>e;

  while (e>0) {
    string buffer;
    std::cin>>buffer;
    append(l, buffer);
    e--;
  }
}

void distruggi(Lista& l) {
  if (l) {
    distruggi(l->next);
    delete l;
    l=nullptr;
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
string concat(Lista l, int pos, int len) {
     int n = lunghezza(l);
     string res="";
    if(pos>n){return res;}
    else{

     for(int i=0;i<pos;i++){         
         l = l ->next;
     }

    for(int j = 0;j<len;j++){
        if(l!=nullptr){
            
            res = res+l->info;
            l = l->next;
        }
    }
    return res;
}   
}

int main() {
  Lista l = nullptr;
  int da, quanti;
/*
5
questa
e
una
prova
!
3
2*/
  leggi(l);

  std::cin>>da;
  std::cin>>quanti;

  std::cout<<concat(l, da, quanti);

  distruggi(l);

  return 0;
}


