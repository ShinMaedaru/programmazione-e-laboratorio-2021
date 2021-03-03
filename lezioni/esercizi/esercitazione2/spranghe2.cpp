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

size_t min(const vector<int>& vin){

    size_t posmax = 0;
    int m =vin.at(posmax);
    for(size_t i=1; i<vin.size();i++){
        if(vin.at(i)<m){
            
            posmax = i;
            m = vin.at(i);
        }
    }
    return vin.at(posmax);
}


int count_positive(const vector<int>& vin){
    int count = 0;
    for(int i:vin){
        if(i>0){
            count++;
        }
    }
    return count;
}

vector<int> rodOffcut(vector<int> lengths) {
    vector<int> res;
    int init = count_positive(lengths);
    res.push_back(init);
    
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
