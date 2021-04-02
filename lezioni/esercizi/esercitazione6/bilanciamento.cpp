#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'getMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
//        bal += s[i] == '(' ? 1 : -1;

int getMin(string s) {
// maintain balance of string
    int bal = 0;
    int ans = 0;
  
    for (int i = 0; i < s.length(); ++i) {
  
        if(s[i] == '('){
            bal+= 1;
        }else{
        bal +=-1;
        }
  
        // It is guaranteed bal >= -1
        if (bal == -1) {
            ans += 1;
            bal += 1;
        }
    }
  
    return bal + ans;

}

int main()
{
    string s="()()";
    int result = getMin(s);

    cout << result << "\n";

    return 0;
}
