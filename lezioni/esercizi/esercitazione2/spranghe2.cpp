#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'rodOffcut' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY lengths as parameter.
 */
void sort(vector<int>& s){ 
   int temp;  
   int n = s.size();
   for (int i = 0; i < n-1; i++) {
      for (int j = i+1; j < n; j++) {
         if (s.at(i) > s.at(j)) {
            temp = s.at(i);
            s.at(i) = s.at(j);
            s.at(j) = temp;
         }
      }
   }
}

vector<int> rodOffcut(vector<int> lengths) {
    sort(lengths);
    vector<int> res;
    int zero = 0;
    while(zero<lengths.size()){
        res.push_back(lengths.size()-zero);
        int min =1000;

    for(int i=0;i<lengths.size();i++){
        if(lengths.at(i)>0 && lengths.at(i)<min){
            min = lengths.at(i);
        }
    }
    for(int i=0;i<lengths.size();i++){
        lengths.at(i) = lengths.at(i)-min;
        if(lengths.at(i)==0)
        zero++;
    }
    }
    return res;
}

int main()
{
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
