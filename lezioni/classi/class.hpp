#include<string>
//codice del file header con solo le implementazioni
//andrebbe visto come una specie di interfaccia di java
class List_int{
    private: 
    struct Cella{
        int info;
        Cella* next;
    };
    Cella* l; //puntatore alla testa
    
    public:
    
    List_int();
   List_int(int el);
    void prepend(int el);
    //metodo che ritorna la lista sottoforma di stringa
    std::string to_string();
};
 


