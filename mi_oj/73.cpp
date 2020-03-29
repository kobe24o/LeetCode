#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    int n, i;
    while(getline(cin, line))
    {
//        istringstream in(line);
        unordered_map<int,int> m;
        for(i = 0; i < line.size(); ++i)
        {
            n = 0;
            while(i < line.size() && line[i] != ',') {
                n = n*10+line[i++]-'0';
            }
            m[n]++;
        }
        for(auto& mi : m)
        {
            if(mi.second == 1)
            {
                cout << mi.first << endl;
                break;
            }
        }
    }
    return 0;
}