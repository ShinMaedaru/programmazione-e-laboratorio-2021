#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

void foo(vector<int>& v){} //by reference
void foo(vector<int> v){} //copia
void foo(const vector<int>& v){} //const reference lo referenzio ma non lo modifico

int main(){
vector<double> mv;//la parte tra graffe è il tipo di dato nel vettore
vector<string> mv1;
mv.push_back(12.3);//se size <= capacity aggiunge un elemento e aumenta la capacity
mv.size(); //size array

for(double& elem: mv){
std::cout<<elem;
}
mv[0] = 14.4;
vector<int> v;
for(const int& h:v){
//con const prometto di non modificarlo 
}


}