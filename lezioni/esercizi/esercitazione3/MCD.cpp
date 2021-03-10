#include <iostream>
using std::cout;
int gcd(int a, int b)
{

    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}
void minimizza(int& a, int& b){
    int MCD = gcd(a,b);
    a = a/MCD;
    b = b/MCD;
}

int lcm(int a, int b) //mimimo comun multiplo
{
    return (a / gcd(a, b)) * b;
}
void FindDenom(int& n1,int& n2,int& den1,int& den2,int& numRes,int& denRes){ //ritrova i denominatori
    int l = lcm(den1,den2);
    if (l == 1){
        numRes = n1 + n2;

    }else{
        n1 = n1*(l/den1);
        n2 = n2*(l/den2);
        denRes = l;
        numRes = n1 + n2;
    }
}
// Driver program to test above function
int main()
{/*
    int a = 0, b = 5;
    int MCD = gcd(a,b);
    minimizza(a,b);
    int l = lcm(a,b);
    */
    int num1 = 3;
    int den1 = 2;
    int num2 = 9;
    int den2 = 5;
    int numRes = 0;
    int denRes = 0;
    cout<<"///////////////////////////////////////"<<std::endl;
  /*  cout<<"GCD of "<<a<<" and "<<b<<" is "<<MCD<<std::endl;
    cout<<"LCM is " <<l<<std::endl;*/
    cout<<num1<<"/"<<den1<<" + "<<num2<<"/"<<den2<<" = "<<std::endl;
    FindDenom(num1,num2,den1,den2,numRes,denRes);
    cout<<numRes<<"/"<<denRes<<std::endl;
    cout<<"///////////////////////////////////////"<<std::endl;

    return 0;
}