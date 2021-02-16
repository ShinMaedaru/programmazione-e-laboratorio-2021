#include <iostream>

int main() {
    int m;//numero da verificare
    int d;//variabile incrementale del ciclo
    bool comp;
    std::cin>>m; //cin permette di prendere un valore da tastiera
    comp = false; //inizializzo la variabile di verifica come false
    for(d=2;d<=m-1;d++){ //vado da 2 a m-1 e continuo a icrementare
    //m è m-1 perchè sappiamo che un numero primo è divisible per n e se stesso
    //quindi se lo dividiamo per lui stesso faremo ritornare true
        if(m%d == 0){ //verifico se m è divisibile per d
            comp = true;//se è vero assegno a comp true       
        }
       
    }
     if (comp || m<2){ 
         //se comp è vero vuol dire che nel ciclo abbiamo trovato un suo divisore
         //se m < 2 allora è 1 che non è un numero primo
            std::cout<<m<<" non è primo"<<std::endl;
        }
    else{
        //altrimenti siamo nel caso false quindi m è primo 
            std::cout<<m<<" è primo"<<std::endl;

    }


    return 0;
}