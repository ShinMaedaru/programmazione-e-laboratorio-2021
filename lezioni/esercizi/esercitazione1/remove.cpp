#include <iostream>
#include <string>
using std::string;

string remove(const string& s){
    string res="";
    for(char car: s){
        if(car!=' '){
            res += car;    
        }

    }
    return res;
}

int main() {
    string a;
    getline(std::cin, a);
     string b = remove(a); 

    std::cout<<b<<std::endl;
   
    return 0;
}