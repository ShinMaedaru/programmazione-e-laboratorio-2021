//giusto
#include <string>
#include <iostream>

using std::string;
void rimuovidoppie(string &s)
{
    int n = s.length();
    string res = "";
     if (n==0){
         s = res;
        return;
    }
    int j=0;
    res.push_back(s.at(j));

    
    for (int i=1;i<n;++i){

     if (s.at(j) != s.at(i)){
          ++j;
          s.at(j) = s.at(i);
         res.push_back(s.at(j));
     }
    }
   
   s = res;
}
int main() {
    string a;
    getline(std::cin, a);

    rimuovidoppie(a);
    
    std::cout<<a<<std::endl;
    
    return 0;
}