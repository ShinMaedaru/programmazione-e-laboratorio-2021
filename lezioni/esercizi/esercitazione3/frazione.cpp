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

int MCD(long a,long b){ //funzione che trova il massimo comun divisiore
      if (b == 0)
        return a;
    return MCD(b, a % b); 
}
void minimizza(long& a, long& b){ //funzione che rende coprimi il numeratore e il denomiatore
    long m = MCD(a,b);
    a = a/m;
    b = b/m;
}

int mcm(int a, int b) //mimimo comun multiplo
{
    return (a / MCD(a, b)) * b;
}

void Frazione::minimi_termini(){ 
    minimizza(numeratore,denominatore);
}

Frazione Frazione::somma(const Frazione &f) const {
    
    return f;
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