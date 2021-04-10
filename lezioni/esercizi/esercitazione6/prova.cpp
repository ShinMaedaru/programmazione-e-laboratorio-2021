#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

int getMin(string s)
{
	int a, c, r;
	a=0;
	c=0;
	r=0;
	for(int i=0; i<s.size();i++)
	{
		if( s[i] == '(' )
		{
			a++;
		}
		else{
			if (( s[i] == ')' ) && (a>0 ))
			{
				a--;
			}
			else{
				c++;
			}
		}
	}
	r=a+c;
	return r;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    cout<<"vecio scrivi le parentesi che vuoi completare"<<endl;
    getline(cin, s);

    int result = getMin(s);
    cout<<result;
    return 0;
}