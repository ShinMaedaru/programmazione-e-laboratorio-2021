#include<iostream>
#include<string>

using std::string;

struct Cella{
  string info;
  Cella* next;
};

typedef Cella* Lista;




void addcircular(Lista& l, int pos, string s){
    Lista nuovo = new Cella();
    nuovo->info = s;
   if(l == nullptr){
        l = nuovo;
        l->next = nuovo;
   }else{
       
        while(pos!=0){
            l= l->next;
            pos--;
        }
        
        nuovo->info = l->info;
        nuovo->next = l->next;
        l->info = s;
        l->next = nuovo;
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

  std::cin>>nelem;

  while (nelem>0) {
    std::cin>>pos;
    std::cin>>str;
    addcircular(mylist, pos, str);
    nelem--;
  }

  print(mylist);

  distruggi(mylist);

  return 0;
}

