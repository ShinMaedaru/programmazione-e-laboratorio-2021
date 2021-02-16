#include <iostream>

void swap(int& a,int& b){
    int c; //variabile temporanea per lo swap
    c=a;
    a=b;
    b=c;

}

int main(){
    int x = 10;
    int y = 5;
    std::cout<<x<<" "<<y<<std::endl;
    swap(x,y);
    std::cout<<x<<" "<<y<<std::endl;

}