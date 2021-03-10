#include<iostream>

struct Container{
    private:
    int a;
    int b;
    public: 
    Container(){} //costruttore vuoto
    void setA(int num){
        a = num;
    };
    void setB(int num){
        b = num;
    };
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }

};