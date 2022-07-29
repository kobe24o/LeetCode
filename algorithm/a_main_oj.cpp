#include <bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& g) {
        int l = -1, r = 1e9, mid, ans;
        while(l <= r)
        {
            mid = (l+r)>>1;
            if(ok(g, mid))
            {
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
    bool ok(vector<vector<int>> g, int t)
    {
        int m = g.size(), n = g[0].size(), num=512;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<int> p, f;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(g[i][j]==1)
                {
                    f.push(i*num+j);
                }
            }
        }
        int firestep = 0;
        while(!f.empty())
        {
            int sizef = f.size();
            while(sizef-- > 0)
            {
                int x = f.front()/num, y = f.front()%num;
                f.pop();
                for(int k = 0; k < 4; ++k)
                {
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && g[nx][ny]!=1 && g[nx][ny]!=2 && firestep < t)
                    {
                        f.push(nx*num+ny);
                        g[nx][ny] = 1; // 标记火访问过了
                    }
                }
            }
            firestep++;
        }
        p.push(0);
        g[0][0] = 3;
        while(!p.empty()) {
            int sizep = p.size();
            while (sizep-- > 0) {
                int x = p.front() / num, y = p.front() % num;
                if (x == m - 1 && y == n - 1)
                    return true;
                p.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] != 2 && g[nx][ny] != 3 && g[nx][ny] != 1) {
                        p.push(nx * num + ny);
                        g[nx][ny] = 3;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,3,4,7,1,2,6};
//    vector<vector<int>> g = {{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    vector<vector<int>> g = {{0,0,0,0},{0,1,2,0},{0,2,0,0}};
//    vector<vector<int>> g = {{0,0,0},{2,2,0},{1,2,0}};
    cout << (s.maximumMinutes(g));
    return 0;
}