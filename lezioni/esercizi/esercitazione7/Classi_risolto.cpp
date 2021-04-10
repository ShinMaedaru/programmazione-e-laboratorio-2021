#include<string>
#include<iostream>

class List_int{
  public:
    List_int();
    List_int(int el);
    List_int(const List_int& source);

    void prepend(int el);    
    void append(int el);
    

    std::string convert_to_string() const;
    void tail(List_int& res);
    int& first();
    const int& first() const;
    
    bool equal(const List_int& comp) const;
    
    void concat(List_int& sec);

    void remove_first();

    ~List_int();
  private:

    struct Cella{
      int info;
      Cella* next;
    };

    Cella* l;     //Punt. prima cella della lista  
    Cella* last;  //Punt. ultima cella della lista
    //Lista vuota codificata con l==last==nullptr
};

List_int::List_int() :l{nullptr}, last{nullptr}  {
} //Crea la lista vuota
    
List_int::List_int(int el) {     
  l = new Cella;
  l->info=el;
  l->next=nullptr;
  last=l;
}


List_int::List_int(const List_int& source) {

  l = nullptr;
  last = nullptr;
  Cella* pc = source.l;
 
  while (pc) {
    append(pc->info);
    pc = pc->next;
  }
}
    
void List_int::prepend(int el) {
  Cella* nuova = new Cella;
  nuova->info = el;
  nuova->next = l;
  l = nuova;
  if (last==nullptr)
    last=nuova;
}

void List_int::append(int el) {
  Cella* nuova = new Cella;
  nuova->info = el;
  nuova->next=nullptr;

  if (l==nullptr) {
    l=nuova;
    last=nuova;
  }
  else {
    last->next = nuova;
    last = nuova;
  }
}

std::string List_int::convert_to_string() const{
  std::string res{};
  Cella* pc{l};

  while (pc) {
    res = res + std::to_string(pc->info) + " ";
    pc = pc->next;
  }
    return res;
}


List_int::~List_int() {
  Cella* pc;
  while(l) {
    pc = l;
    l=l->next;
    delete pc;
  }
}

void List_int::tail(List_int& res) {   
  Cella* pc{l->next};

  while (pc) {
    res.append(pc->info);
    pc = pc->next;
  }
} 


int& List_int::first() {  
  return l->info;
}


const int& List_int::first() const {
  return l->info;
}

void List_int::remove_first() {
  if (l) {
    Cella* pc = l;
    l=l->next;
    delete pc;
    if (l==nullptr) 
      last = nullptr; 
  }
}




bool List_int::equal(const List_int& comp) const {

      Cella* pc = l;
      Cella* pc2= comp.l;
      bool temp = true; 
      while (pc != NULL && pc2 != NULL){
        if (pc->info != pc2->info)
            temp= false;

        pc = pc->next;
        pc2 = pc2->next;
    }
    if(pc == NULL && pc2 == NULL){
        temp = true;
    }else{
        temp =false; 
    }    
    return temp;
}


void List_int::concat(List_int& sec) {
    
    while(sec.l){
        if(l){
        last->next = sec.l;
        last = sec.l;
        }
        else{
             l=sec.l;
             last=sec.l;
        }
        sec.l=sec.l->next;

    }
}

void read_list(List_int& l) {
  int elem, member;
  std::cin>>elem;

  while (elem>0) {
    std::cin >> member;
    l.append(member);
    elem--;
  }
}


int main() {
  List_int l1, l2;   //crea due liste vuote

 
  read_list(l1);
  read_list(l2);

  if (l1.equal(l2)) 
    std::cout << "Liste uguali" << std::endl;
  else
    std::cout << "Liste diverse" << std::endl;

  l1.concat(l2);

 

  std::cout<<l1.convert_to_string()<< std::endl;
  std::cout<<l2.convert_to_string()<< std::endl;

  return 0;
}