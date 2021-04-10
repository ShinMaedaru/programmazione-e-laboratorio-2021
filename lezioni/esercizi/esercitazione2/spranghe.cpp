#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int count_positive(const vector<int>& vin){
    int count = 0;
    if (vin.empty()){
        return 0;
    }else{
    for(int i:vin){
        if(i>0){
            count++;
        }
    }
    return count;
    }
}

vector<int> positiveArray(const vector<int>& vin){
    vector<int> res;
    if (vin.empty()){
        return vin;
    }else{
    for(int i:vin){
        if(i>0){
            res.push_back(i);
        }

    }
    return res;
    }
}

int min(const vector<int>& vin){
    
    int posmax = 0;
    int m =vin.at(posmax);
    for(size_t i=1; i<vin.size();i++){
        if(vin.at(i)<m){
            
            posmax = i;
            m = vin.at(i);
        }
    }
    return vin.at(posmax);
}


/*
 * Complete the 'rodOffcut' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY lengths as parameter.
 */



vector<int> rodOffcut(vector<int> lengths) {
    vector<int> a; //vettore con solo i positivi
    vector<int> res; //vettore con il numero di positivi

    int minore; // il valore minore nel ciclo attuale
    int temp2;
    int size;
    a = positiveArray(lengths);
    size = a.size();

        while(size==0){ 
            minore = min(a); //imposto il minore
            res.push_back(a.size()); //salvo il numero di positivi al ciclo attuale   
            for(size_t i=0;i<a.size();++i){
                temp2 = a.at(i)-minore;
                a.at(i) = temp2;
            }
             a = positiveArray(lengths);
             size = a.size();

        }
    
    return res;
}

int main()
{
    /*
    ofstream fout(getenv("OUTPUT_PATH"));

    string lengths_count_temp;
    getline(cin, lengths_count_temp);

    int lengths_count = stoi(ltrim(rtrim(lengths_count_temp)));

    vector<int> lengths(lengths_count);

    for (int i = 0; i < lengths_count; i++) {
        string lengths_item_temp;
        getline(cin, lengths_item_temp);

        int lengths_item = stoi(ltrim(rtrim(lengths_item_temp)));

        lengths[i] = lengths_item;
    }

    vector<int> result = rodOffcut(lengths);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();
*/
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    vector<int> res;
    
 //   v = positiveArray(v);
   // int temp = min(v);
   res = rodOffcut(v);
   for(int i:res){
    cout<<i<<endl; 
    }
   // cout<<"positivi sono "<<count_positive(v)<<endl; 

    return 0;
}