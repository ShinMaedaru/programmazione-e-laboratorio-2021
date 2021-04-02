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
//			cout<<a<<endl;
		}
		else{
			if (( s[i] == ')' ) and (a>0 ))
			{
				a--;
//				cout<<a<<endl;
			}
			else{
				c++;
//				cout<<c<<endl;
			}
		}
	}
//	cout<<a<<endl;
//	cout<<c<<endl;
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