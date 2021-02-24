#include <iostream>
#include <string>

using std::string;


void sort(string& s){

   char temp;
   
   int n = s.length();


   for (int i = 0; i < n-1; i++) {
      for (int j = i+1; j < n; j++) {
         if (s.at(i) > s.at(j)) {
            temp = s.at(i);
            s.at(i) = s.at(j);
            s.at(j) = temp;
         }
      }
   }
}

string remove(const string& s){
    string res="";
    for(char car: s){
        if(car!=' '){
            res += car;    
        }

    }
    return res;
}

bool anagramma(string s1, string s2)
{
    string s1_nospace = remove(s1);
    string s2_nospace = remove(s2);
    sort(s1_nospace);
    sort(s2_nospace);
    if ( s1_nospace==s2_nospace){
        return true;
    }else{
        return false;
    }
}

int main() {
    string a, b;
    getline(std::cin, a);
    getline(std::cin, b);
    
    if (anagramma(a,b))
        std::cout << "Si" <<std::endl;
    else
        std::cout << "No" <<std::endl;
    return 0;
}