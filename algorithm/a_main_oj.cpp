#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 500, p=1, id=0, m = 3;
    cin >> p;
    for(int i = 1; i <= N; ++i)
    {
        id = (id+m)%i;
        if(i == p)
        {
            cout << id+1 << endl;
            cin >> p;
        }
    }
    
    return 0;
}