#include <iostream>
#include <cmath>

struct complex{
    private: 
    double r;
    double i;
    public: 
    complex(): r{0.0},i{0.0}{}
    complex(double real,double immage):r{real},i{immage}{};
    complex(double m,double arg,bool b){
        r = m*cos(arg); //libreria cmath
        i = m*sin(arg); //libreria cmath

    }
    complex somma(const complex& a){
            
    }
    void diminuisci(){
        i = -i;
    }
};
 complex::complex(double m,double arg,bool b){
        r = m*cos(arg); //libreria cmath
        i = m*sin(arg); //libreria cmath

    }
int main(){
   
}