#include <iostream>
#include <vector>
using std::cout;
using std::vector;

bool ordine(vector<int>& v){
    int n = v.size();
    bool inv = true;

     for (int i = 0; i < n-1; i++) {
        if(inv){
          if(v[i+1]-v[i] == 1||v[i+1]-v[i] == 0){
            inv = true;
          }
          else{
              inv = false;         
          }
        }
    }
    
     return inv;
}

void sort(vector<int>& v){    
   char temp;
   int n = v.size();

   for (int i = 0; i < n-1; i++) {
      for (int j = i+1; j < n; j++) {
         if (v.at(i) > v.at(j)) {
            temp = v.at(i);
            v.at(i) = v.at(j);
            v.at(j) = temp;
         }
      }
   }
}

int main(){
    vector<int> v{1,2,2,3};
    for(int i:v){
        cout<<i<<" ";
    }

    if (ordine(v)){
        cout<<"vettore ordinato strettamente maggiore di 0 "<<std::endl;
    }
    else{
        cout<<"vettore non ordinato "<<std::endl;
        
    }
    return 0;
}