#include<iostream>
#include<string>

using std::string;

struct Cella{
  string info;
  Cella* next;
};

typedef Cella* Lista;




void addcircular(Lista& testa, int pos, string s){
    Lista nuovo = new Cella();
    nuovo->info = s;
   if(testa == nullptr){
        testa = nuovo;
        testa->next = nuovo;
   }else{
       
        while(pos!=0){
            testa= testa->next;
            pos--;
        }
        
        nuovo->info = testa->info;
        nuovo->next = testa->next;
        testa->info = s;
        testa->next = nuovo;
       }
   }
void print(Lista l) {
  if (l) {
    Lista pc = l;
    do {
      std::cout<<pc->info<<std::endl;
      pc = pc->next;
    } while (pc!=l);
  }
}


void distruggi(Lista& l) {
  if (l) {
    Lista pc = l;
    do {
      Lista supp = pc->next;
      delete pc;
      pc = supp;
    } while (pc!=l);
  }
  l=nullptr;
}


int main() {
  Lista mylist = nullptr;

  int nelem;
  int pos;
  string str;
  std::cout<<"/////////////////////////////"<<std::endl;
  
  std::cin>>nelem;
  std::cout<<"/////////////////////////////"<<std::endl;

  while (nelem>0) {
    std::cin>>pos;
    std::cin>>str;
    addcircular(mylist, pos, str);
    nelem--;
  }
  std::cout<<"/////////////////////////////"<<std::endl;
  print(mylist);

  distruggi(mylist);

  return 0;
}

