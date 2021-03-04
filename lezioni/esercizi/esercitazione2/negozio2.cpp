#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'featuredProduct' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY products as parameter.
 */
bool comparator(string a,string b)
{
    return a<b;
}

size_t max(const vector<int>& vin){

    size_t posmax = 0;
    int m =vin.at(posmax);
    for(size_t i=1; i<vin.size();i++){
        if(vin.at(i)>=m){
            
            posmax = i;
            m = vin.at(i);
        }
    }
    return posmax;
}

string featuredProduct(vector<string> products) {
    sort(products.begin(),products.end(),comparator);
    int index;
    vector<int> occorrenze;
    for(string i:products){
        //cout<<i<<" ";
        occorrenze.push_back(count(products.begin(),products.end(),i));
    }
    index = max(occorrenze);
    //cout<<endl;

    for(int i:occorrenze){
        //cout<<i<<" ";
    }
    return products.at(index); 

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string products_count_temp;
    getline(cin, products_count_temp);

    int products_count = stoi(ltrim(rtrim(products_count_temp)));

    vector<string> products(products_count);

    for (int i = 0; i < products_count; i++) {
        string products_item;
        getline(cin, products_item);

        products[i] = products_item;
    }

    string result = featuredProduct(products);

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
