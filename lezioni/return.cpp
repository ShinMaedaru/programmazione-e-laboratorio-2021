#include <iostream>

int& min(int& a, int& b){
    if (a<b){
        return a;
    }
    else{return b;}
}

int main(){
    int x=3;
    int y=4;
    min(x,y) =0;
    return 0;
}