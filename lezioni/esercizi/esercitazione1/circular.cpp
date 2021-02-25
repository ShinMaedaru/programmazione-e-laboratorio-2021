#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'getTime' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING s as parameter.
 */

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


long getTime(string s) {
    string s1 = s;
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
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long result = getTime(s);


    fout << result << "\n";

    fout.close();

    return 0;
}
