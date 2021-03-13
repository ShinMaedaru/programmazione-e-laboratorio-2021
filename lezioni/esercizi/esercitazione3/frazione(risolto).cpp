
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


long MCD(long num,long den){//funzione che trova il massimo comun divisiore
    if(den==0){ //quella vista a lezione con il prof marin mi dava errore quindi ho usato questa formula
        return num;
    }
    return MCD(den,num%den);
}
long mcm(long a,long b){ //mimimo comun multiplo
    long res = (a/MCD(a,b))*b;
    return res;
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

void Frazione::minimi_termini(){
     
    minimizza(numeratore,denominatore);
    
}
Frazione Frazione::somma(const Frazione &f) const{
    Frazione res{0,0};
    //Inizializzo ogni numerato e denominatore per facilitare la scrittura e lettura
    long num1 = numeratore; 
    long den1 = denominatore;
    long num2 = f.numeratore;
    long den2 = f.denominatore;
    long minComunMuliplo = mcm(den1,den2);
    if(minComunMuliplo == 1){
        res.denominatore = den1;
        res.numeratore = num1 + num2;
        return res;
    }
    else{
        num1 = num1*(minComunMuliplo/den1);
        num2 = num2*(minComunMuliplo/den2);
        res.denominatore = minComunMuliplo;
        res.numeratore = num1 + num2;
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