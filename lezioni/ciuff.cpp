#include <iostream>
#include <string>

using std::string;

int main(){

    string s = "pippo";

    for(char c:s){ 
        std::cout<<c<<std::endl;    
    }
    for(int i; i<s.length();++i){
        std::cout<<s.at(i)<<std::endl;    

    }

    return 0;
}
