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

int getMaxValue(vector<int> arr) {
    sort(arr.begin(),arr.end()); //ordino l'array in modo crescente
    arr.at(0) = 1; //in un array ordinato il minimo è sempre alla prima posizione quindi la setto a 1
    int n= arr.size();
        for(int i = 0;i<n-1;++i){
            if(arr.at(i+1)-arr.at(i) > 1){ //se l'elemento precedente meno l'attuale sono minori di 1 
                arr.at(i+1) = arr.at(i)+1; //all'elemento seguente sommo l'attuale +1 per validare il constraint iniziale 
        }
    
}   
    return arr.at(n-1); 
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
