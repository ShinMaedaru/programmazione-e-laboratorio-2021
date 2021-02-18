#include <iostream>
#include "funzioni.hpp"
int main(){
    int x;
    int y;
    int m;
    std::cin>>x;
    std::cin>>y;
    m = mcd(x,y);
    if (multipli(x,y)){
      std::cout<<x<<" è multiplo di "<<y<<std::endl;

    }
    else{
      std::cout<<x<<" non è multiplo di "<<y<<std::endl;

    }
    return 0;
}