class Solution {
    char ch[3] = {'a','b','c'};
    vector<string> ans;
    string s;
    int N, K;
public:
    string getHappyString(int n, int k) {
        N = n;
        K = k;
        dfs(s);
        if(k > ans.size())
            return "";
        return ans[k-1];
    }

    void dfs(string s)
    {
        if(ans.size()>=K)
            return;
        if(s.size()==N)
        {
            ans.push_back(s);
            return;
        }
        for(int i = 0; i < 3; ++i)
        {
            if(s.empty() || s.back()!=ch[i])
                dfs(s+ch[i]);
        }
    }
};