#include <iostream>
#include <string>
struct Cella{
    
    int info;
    struct Cella* next;
};
//aggiunge in testa 
typedef struct Cella* Lista;

void elimina_dup(Lista& l)
{
  for(Lista iter = l; iter != nullptr && iter->next != nullptr; iter = iter->next) 
    if(iter->info == iter->next->info) {
      Lista temp = iter->next;
      iter->next = iter->next->next;
      // free(temp);
    }
}
