#include"class.hpp"
#include<iostream>
#include<string>
int main(){
    List_int l1;//creo lista vuota
    List_int l2(4);//creo lista nuova
    l2.prepend(5);
    //esmpio di utilizzo:inserisco la stringa in una variabile
    std::string list=l2.to_string();
    std::cout<<l2.to_string()<<std::endl;
    return 0;
}