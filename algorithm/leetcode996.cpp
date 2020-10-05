class Solution {
    int ans = 0;
public:
    int numSquarefulPerms(vector<int>& A) {
        vector<bool> vis(A.size(), false);
        sort(A.begin(), A.end());
        dfs(A, 0, -1, vis);
        return ans;
    }
    void dfs(vector<int>& A, int count, int prev, vector<bool>& vis) 
    {
        if(count == A.size())
        {
            ans++;
            return;
        }
        
        for(int i = 0; i < A.size(); ++i)
        {
            if(i > 0 && !vis[i-1] && A[i-1]==A[i])
                continue;
            if(!vis[i] && (prev == -1 || ok(prev, A[i])))
            {
                vis[i] = true;
                dfs(A, count+1, A[i], vis);
                vis[i] = false;
            }
        }
    }
    bool ok(int a, int b)
    {
        int num = sqrt(a+b);
        return num*num == a+b;
    }
};