#include <iostream>
#include <string>
using std::string;

void sort(string& s){
    string res="";
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

int main() {
    string a;
    getline(std::cin, a);
     sort(a);

    std::cout<<a<<std::endl;
   
    return 0;
}