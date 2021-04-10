#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'maxHeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY wallPositions
 *  2. INTEGER_ARRAY wallHeights
 */

int maxHeight(vector<int> wallPositions, vector<int> wallHeights) {
 int n = wallPositions.size();
 int m = wallHeights.size();
 int max =0;
 int low =0;
 int massimoAttuale=0;
 int gap=0;
 int differenza=0;
 
 for(int i =0;i<n-1;i++){
     if(wallPositions.at(i)<wallPositions.at(i+1)-1){
        differenza = abs(wallHeights.at(i+1)-wallHeights.at(i));
        gap = wallPositions.at(i+1) - wallPositions.at(i)-1;
        massimoAttuale=0;
         if(gap>differenza){
             if(wallHeights.at(i+1)>wallHeights.at(i)){
                 low = wallHeights.at(i+1)+1;
             }else{
                 low = wallHeights.at(i)+1;
             }
             int resto = gap-differenza-1;
             massimoAttuale=low+resto/2;
             
         }else {
             if(wallHeights.at(i+1)<wallHeights.at(i)){
                 massimoAttuale = wallHeights.at(i+1)+gap;
             }else{
                 massimoAttuale = wallHeights.at(i)+gap;
             }
         }
          if(max<massimoAttuale){
                 max = massimoAttuale;
             }else{
                 max = max;
             }
        
     }
 }
 return max;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string wallPositions_count_temp;
    getline(cin, wallPositions_count_temp);

    int wallPositions_count = stoi(ltrim(rtrim(wallPositions_count_temp)));

    vector<int> wallPositions(wallPositions_count);

    for (int i = 0; i < wallPositions_count; i++) {
        string wallPositions_item_temp;
        getline(cin, wallPositions_item_temp);

        int wallPositions_item = stoi(ltrim(rtrim(wallPositions_item_temp)));

        wallPositions[i] = wallPositions_item;
    }

    string wallHeights_count_temp;
    getline(cin, wallHeights_count_temp);

    int wallHeights_count = stoi(ltrim(rtrim(wallHeights_count_temp)));

    vector<int> wallHeights(wallHeights_count);

    for (int i = 0; i < wallHeights_count; i++) {
        string wallHeights_item_temp;
        getline(cin, wallHeights_item_temp);

        int wallHeights_item = stoi(ltrim(rtrim(wallHeights_item_temp)));

        wallHeights[i] = wallHeights_item;
    }

    int result = maxHeight(wallPositions, wallHeights);

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
