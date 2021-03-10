#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'getMaxValue' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
 void sort(vector<int>& v){ //funzione che riordina un array   
   int temp;
   int n = v.size();

   for (int i = 0; i < n-1; i++) {
      for (int j = i+1; j < n; j++) {
         if (v.at(i) > v.at(j)) {
            temp = v.at(i);
            v.at(i) = v.at(j);
            v.at(j) = temp;
         }
      }
   }
}

int posmin(const vector<int>& vin){

    int posmin = 0;
    int m =vin.at(posmin);
    for(int i=1; i<vin.size();i++){
        if(vin.at(i)<=m){
            
            posmin = i;
            m = vin.at(i);
        }
    }
    return posmin;
}
bool ordine(vector<int>& v){
    int n = v.size();
    bool inv = true;

     for (int i = 0; i < n-1; i++) {
        if(inv){
          if(v[i+1]-v[i] <= 1){
            inv = true;
          }
          else{
              inv = false;         
          }
        }
    }
    
     return inv;
}

void swap(int& a,int& b){
    int c; //variabile temporanea per lo swap
    c=a;
    a=b;
    b=c;

}

int getMaxValue(vector<int> arr) {
    sort(arr.begin(),arr.end());
    //sort(arr);
    //int min = posmin(arr);
    //swap(arr.at(min),arr.at(0));
    arr.at(0) = 1;
    int n= arr.size();
        for(int i = 0;i<n-1;++i){
            if(arr[i+1]-arr[i] > 1){
                arr[i+1] = arr[i]+1;
        }
    
}   
 
    return arr[n-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = getMaxValue(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
