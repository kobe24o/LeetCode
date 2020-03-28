#include <bits/stdc++.h>

using namespace std;

int main()
{
    // please write your code here
    int n, k;
    while(cin>>n)
    {
    	k = 0;
    	int a=0, b=1, sum = 0;
    	while(k++ < n)
    	{
    		sum = a+b;
    		a = b;
    		b = sum;
    	}
    	cout << sum << endl;
    }
    return 0;
}