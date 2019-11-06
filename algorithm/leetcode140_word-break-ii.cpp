#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int i, j, n = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        bool dp[n+1] = {false};//dp[j]包含第j个字符为结尾的字符能否拆分
        dp[0] = true;//空字符能拆分
        for(i = 0; i <= n; ++i)
        {
            if(dp[i] == true)//左半边存在
                for(j = i+1; j <= n; ++j)
                {
                    if(set.count(s.substr(i,j-i)))
                        dp[j] = true;
                }
        }
        if(dp[n] == true)//整个字符串可以拆
        {
            vector<string> ans;
            string str;
            int end = 1;
            while(end <= n && dp[end] != 1)
                end++;
            bt(s,set,dp,ans,str,0,end);
            return ans;
        }
        else
            return {};
    }

    void bt(string &s, unordered_set<string> &set, bool *dp, vector<string> &ans,
            string str, int start, int end)
    {
        if(start >= end)
            return;
        string temp = s.substr(start,end-start);
        bool inSet = set.count(temp);
        if(end == s.size())
        {
            if(inSet)
                ans.push_back(str+temp);
            return;
        }
        int next = end+1;
        while(next <= s.size() && dp[next] != 1)
            next++;
        bt(s,set,dp,ans,str,start,next);//不插入空格
        if(inSet)
            bt(s,set,dp,ans,str+temp+" ",end,next);
    }
};
int main()
{
    Solution s;
    vector<string> v = {"cat", "cats", "and", "sand", "dog"};
    s.wordBreak("catsanddog",v);
}