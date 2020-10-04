#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
            return 0;
        queue<int> q;
        unordered_set<int> vis;
        vis.insert(n);
        int step = 0, size;
        q.push(n);
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                int cur = q.front();
                if(cur == 0)
                    return step;
                q.pop();
                int nt = ((cur>>1)<<1)|(~(cur&1));
                if(!vis.count(nt))
                {
                    q.push(nt);
                    vis.insert(nt);
                }
                bool foundone = false;
                int i;
                for(i = 0; i < 31; i++)
                {
                    if(((cur>>i)&1)){
                        foundone = true;
                        break;
                    }
                }
                if(foundone &&  i+1 < 32)
                {
                    nt = (cur&(~(1<<(i+1))))|((~((cur>>(i+1))&1))<<(i+1));
                    if(!vis.count(nt))
                    {
                        q.push(nt);
                        vis.insert(nt);
                    }
                }
            }
            step++;
        }
        return step;
    }
};
int main()
{
    // Solution s;
    vector<int> r = {3,8}, c = {4,7};
    vector<string> n = {"a","a","a","a","a","b","b","b","b","b","b"};
    vector<string> t = {"23:20","11:09","23:30","23:02","15:28","22:57","23:40","03:43","21:55","20:38","00:19"};
    // s.minimumOneBitOperations(3);
    int cur = 3;
    cout << (~(cur&1)) << endl;
    cout << ((cur>>1)<<1) << endl;
    cout << (((cur>>1)<<1)|(~(cur&1))) << endl;
    return 0;
}