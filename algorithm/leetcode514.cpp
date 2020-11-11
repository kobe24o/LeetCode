class Solution {//超时
    int steps = INT_MAX;
    int n;
    vector<vector<int>> pos(26);
public:
    int findRotateSteps(string ring, string key) {
        n = ring.size();
        for(int i = 0; i < ring.size(); i++)
            pos[ring[i]-'a'].push_back(i);
        dfs(key, 0, 0, 0);
        return steps;
    }
    void dfs(string& key, int start, int i, int step)
    {
        if(step >= steps)
            return;
        if(i == key.size())
        {
            if(step < steps)
                steps = step;
            return;
        }
        for(int j = 0; j < pos[key[i]-'a'].size(); j++)
        {
            int delta = min(abs(start-pos[key[i]-'a'][j]), n-abs(start-pos[key[i]-'a'][j]));
            dfs(key, i+1, step+delta+1);
        }
    }
};

class Solution {    //记忆化递归
    int n;
    vector<vector<int>> pos;
    vector<vector<int>> memo;
public:
    int findRotateSteps(string ring, string key) {
        n = ring.size();
        pos.resize(26);
        memo = vector<vector<int>> (101, vector<int>(101, INT_MAX));
        for(int i = 0; i < ring.size(); i++)
            pos[ring[i]-'a'].push_back(i);
        return dfs(key, 0, 0, 0);
    }
    int dfs(string& key, int start, int i, int step)
    {
        if(memo[start][i] != INT_MAX)
            return memo[start][i];
        if(i == key.size())
        {
            return 0;
        }
        for(int j = 0; j < pos[key[i]-'a'].size(); j++)
        {
            int delta = min(abs(start-pos[key[i]-'a'][j]), n-abs(start-pos[key[i]-'a'][j]));
            int s = dfs(key, pos[key[i]-'a'][j], i+1, 0);
            memo[start][i] = min(memo[start][i], s+delta+1);
        }
        return memo[start][i];
    }
};

class Solution {    //DP
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        vector<vector<int>> pos(26);
        vector<vector<int>> dp(101, vector<int>(101, INT_MAX));
        for(int i = 0; i < ring.size(); i++)
            pos[ring[i]-'a'].push_back(i);
        for(int i = 0; i < key.size(); ++i)
        {
            for(int j = 0; j < pos[key[i]-'a'].size(); j++)
            {
                
                if(i == 0)
                {
                    int delta = min(pos[key[i]-'a'][j], n-pos[key[i]-'a'][j]);
                    dp[i][j] = min(dp[i][j], delta+1);
                }
                else
                {
                    for(int k = 0; k < pos[key[i-1]-'a'].size(); k++)
                    {   //上一个字符的状态
                        int delta = min(abs(pos[key[i-1]-'a'][k]-pos[key[i]-'a'][j]), n-abs(pos[key[i-1]-'a'][k]-pos[key[i]-'a'][j]));
                        dp[i][j] = min(dp[i][j], dp[i-1][k]+delta+1);
                    }
                }
            }
        }
        int len = key.size();
        return *min_element(dp[len-1].begin(), dp[len-1].end());
    }
};