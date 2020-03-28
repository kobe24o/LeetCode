#include <bits/stdc++.h>

using namespace std;
void sub(string&a, string&b)
{
    int i = a.size()-1, j = b.size()-1, carry = 0, sum;
    while(i >=0 || j >=0 || carry!=0)
    {
        sum = (i>=0 ? a[i]-'0' : 0) - (j>=0 ? b[j]-'0' : 0) - carry;
        if(sum < 0)
        {
            carry = 1;
            sum += 10;
        }
        else
            carry = 0;
        a[i] = sum%10 + '0';
        i--,j--;
    }
}
int main()
{
    // please write your code here
    string a, b;
    int i;
    while(cin>>a)
    {
        i = a.find("-");
        b = a.substr(i+1);
        a = a.substr(0,i);
        sub(a,b);
        if(a.front()=='0')
            cout << a.substr(1) << endl;
        else
            cout << a << endl;
    }
    return 0;
}