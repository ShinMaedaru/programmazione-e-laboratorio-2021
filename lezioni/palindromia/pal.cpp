#include <iostream>
using std::string;
 bool palindroma(const string& s){
     bool res{true};
     int i{0};
     while(i<s.length()/2 && res){
            if(s.at(i) != s.at(s.length()-1-i)){
                    res = false;
            }
     }
     return res;
 }

 int main(){
     
     string s{"anna"};

     if(palindroma(s)){
         std::cout<<" palindroma"<<std::endl;

     }
     else{
          std::cout<<"non palindroma"<<std::endl;

     }
     
     return 0;}