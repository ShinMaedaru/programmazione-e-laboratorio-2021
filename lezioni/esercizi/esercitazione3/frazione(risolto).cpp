#include<iostream>

class Frazione{
    private:
    long numeratore;
    long denominatore;
    
    public:
    Frazione(): numeratore{0}, denominatore{1} {};
    Frazione(long n, long d): numeratore{n}, denominatore{d} {};
    
    void stampa() const {
        std::cout<<numeratore<<"/"<<denominatore<<std::endl;
    }
    
    Frazione somma(const Frazione& f) const;
    
    void minimi_termini();
};


long MCD(long a,long b){ //funzione che trova il massimo comun divisiore
      if (b == 0)
        return a;
    return MCD(b,a%b); 
}
void minimizza(long& num, long& den){ //funzione che rende coprimi il numeratore e il denomiatore
    long m = MCD(num,den);
    num = num/m;
    den = den/m;
    if (den<0){
        num = num*(-1);
        den = den*(-1);
    }
}

long mcm(long a,long b) //mimimo comun multiplo
{
    return (a/MCD(a,b))*b;
}

void Frazione::minimi_termini(){
     
    minimizza(numeratore,denominatore);
    
}
Frazione Frazione::somma(const Frazione &f) const{
    Frazione res{0,0};
    long num1 = numeratore;
    long den1 = denominatore;
    long num2 = f.numeratore;
    long den2 = f.denominatore;
    long l = mcm(den1,den2);
    if(l == 1){
        res.denominatore = den1;
        res.numeratore = num1 + num2;
        return res;
    }
    else{
        num1 = num1*(l/den1);
        num2 = num2*(l/den2);
        res.denominatore = l;
        res.numeratore = num1 +num2;
        return res;        
    }
}
int main() {
    long n1, n2, d1, d2;
    
    std::cin>>n1>>d1>>n2>>d2;
    
    Frazione f1{n1, d1};
    Frazione f2{n2, d2};
    
    Frazione res = f1.somma(f2);
    
    res.minimi_termini();
    
    res.stampa();
    
    return 0;
    
}