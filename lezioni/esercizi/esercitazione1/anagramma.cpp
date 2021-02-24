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

bool anagramma(string s1, string s2)
{
    string s1_nospace = remove(s1);
    string s2_nospace = remove(s2);
    
 
    return true;
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