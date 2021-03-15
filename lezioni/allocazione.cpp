#include <iostream>

double* crea(){
    double* nuovo;
    nuovo = new double;
    *nuovo = 3.14;
    return nuovo;

}

double* pd = new double{3.14};
struct complex{
    double real; 
    double im;
    void azzera(){
        real = 0;
        im = 0;
    }
};

int main(){
        complex* pc;
        pc = new complex{12,-4}; 
        pc -> azzera(); //dereferenzia pc e prende il metodo azzera
        delete pc;

    double* mio; 
    //affido la cella a un altra variabile
    mio = crea(); 
    //no garbage perchè affido la variabile a un altra
    delete mio; 
    //ma devo deletare il mio perche affido la cella a un altro
}
