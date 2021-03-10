#include <iostream>
#include <string>
#include <vector>
    struct Complex{//lettera maiuscola perchè nuovo tipo
        double r;
        double c;
        void azzerati(){
                r =0.0;
                c =0.0;
            };
    Complex somma(Complex a){
        Complex res{a};
        res.r += r;
        res.c += c;
       
    };

};

 
int main(){
    Complex a{2.0,5.0}; 
    Complex b{4.0,5.0}; 

    Complex c;
    c = a.somma(b); //somma b;
  
    return 0;
}