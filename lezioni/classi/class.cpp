#include"class.hpp"
#include<string>
#include<iostream>
//file in cui inserisco unicamente le implementazioni dei metodi
List_int::List_int():l{nullptr}{};

List_int::List_int(int el){ 
       l = new Cella;
       l->info=el;
       l->next=nullptr;
   }
void List_int::prepend(int el){
        Cella* nuova  = new Cella{el,l};
        l=nuova;
    };

    std::string List_int::to_string(){
        std::string res{};
        Cella* pc{l};
        while(pc){
            res = res+std::to_string(pc->info)+ " ";
            pc =pc ->next;

        }
        return res;
    }
 


int main(){
    List_int l1;//creo lista vuota
    List_int l2(4);//creo lista nuova
    l2.prepend(5);
    //esmpio di utilizzo:inserisco la stringa in una variabile
    std::string list=l2.to_string();
    std::cout<<l2.to_string()<<std::endl;
    return 0;
}