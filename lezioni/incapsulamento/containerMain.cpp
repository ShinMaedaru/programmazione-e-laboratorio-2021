#include<iostream>
#include "container.hpp"

using std::cout;
int main(){
    Container c{};
    c.setA(5);
    c.setB(7);
    int res1 = c.getA();
    int res2 = c.getB();
 
    cout <<"il valore di A: " << res1 << " il valore di B " << res2 << std::endl;

    return 0;
}