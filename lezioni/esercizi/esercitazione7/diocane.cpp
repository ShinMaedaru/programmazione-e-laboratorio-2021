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
