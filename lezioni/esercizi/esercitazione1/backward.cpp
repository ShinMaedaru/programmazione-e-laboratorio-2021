#include <bits/stdc++.h>

using namespace std;


/*void clockwise(string s){
    int dim = s.length();
    for(int i =0;i<dim;++i){

        cout<<s.at(i);

    }
    cout<<endl;
}*/

/*void clockWise(string s){
    int dim = s.length();
    for(int i = dim-1;i>=0;--i){
           cout<<s.at(i);
    }
    cout<<endl;

}*/

int clockWise(char c,string s,int& index){//funziona
    int i=index;
    int dim = s.length();
    int steps = 0;
  //  char temp; 
    while(c!=s.at(i)){
        if(i==dim-1){
            i=-1;
        }
        steps++;
        ++i;
        index = i;
    }
    return steps;
}

int counterClockWise(char c,string s,int& index){//funziona
    int i=index;
    int dim = s.length();
    int steps = 0;
    while(c!=s.at(i)){
        if (i==0){
            i=dim;
        }
        steps++;
        --i;
        index = i;
    }
    return steps;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s = "bza";
    string s2 ="abcdefghilmnopqrstuvz";
    int index1=0;
    int index2=0;
    int result;
    int ccw;
    int cw;
    for (char c:s){
            cw = clockWise(c,s2,index2);
            ccw =counterClockWise(c,s2,index1);
        if (cw<ccw){
            result += cw;
            index2= index1;
        }
        else{
            result +=  ccw;
            index1= index2;

        }
    }

    cout<<result;
    return 0;
}
