#include <bits/stdc++.h>

using namespace std;


struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        if(words.size() == 1)
        {
            sort(words[0].begin(), words[0].end());
            words[0].erase(unique(words[0].begin(), words[0].end()),words[0].end());
            return words[0];
        }
        unordered_map<char,set<char>> g;
        unordered_map<char, int> indegree;
        int n1, n2, n;
        for(int i = 1, j; i < words.size(); ++i)
        {
            if(words[i-1] == words[i])
                continue;
            n1 = words[i-1].size();
            n2 = words[i].size();
            n = min(n1, n2);
            for(j = 0; j < n; ++j)
            {
                if(words[i-1][j] != words[i][j])
                {	//不相等的第一个构成有向图的边
                    if(!g.count(words[i-1][j]) || !g[words[i-1][j]].count(words[i][j]))
                    {   //防止重复添加同一条边 "za","zb","ca","cb"
                        g[words[i-1][j]].insert(words[i][j]);
                        indegree[words[i][j]]++;
                        indegree[words[i-1][j]] += 0;
                    }
                    break;
                }
            }
            if(j == n && n1 > n2)
                return "";//前面相等，前者长不行
        }
        priority_queue<char,vector<char>, cmp> q;
        for(auto it = indegree.begin(); it != indegree.end(); it++)
        {
            if(it->second == 0)
                q.push(it->first);
        }
        set<char> set;
        for(auto& w : words)
            for(auto c : w)
                set.insert(c);
        string ans;
        while(!q.empty())
        {
//            int size = q.size();
//            while(size--) {
            char c = q.top();
            q.pop();
            ans += c;
            set.erase(c);
            for (auto it = g[c].begin(); it != g[c].end(); it++) {
                if (--indegree[*it] == 0)
                    q.push(*it);
            }
//            }
        }

        if(!q.empty())
            return "";
        string res;
        auto it = set.begin();
        int i = 0;
        for(; it != set.end() && i < ans.size(); )
        {
            if(ans[i] < *it)
            {
                res += ans[i];
                i++;
            }
            else
            {
                res += *it;
                it++;
            }

        }
        while(i < ans.size())
        {
            res += ans[i];
            i++;
        }
        while(it != set.end())
        {
            res += *it;
            it++;
        }
        return res;
    }
};

int main()
{
     Solution s;
    vector<int> r = {1,2,3,4,5,6}, c = {4,7};
    vector<string> n = {"wrt","wrf","er","ett","rftt"};
//    vector<string> n = {"yy","x"};
    vector<string> t = {"23:20","11:09","23:30","23:02","15:28","22:57","23:40","03:43","21:55","20:38","00:19"};

    vector<vector<int>> g = {{1,2},{2,3},{2,4}};
    cout << s.alienOrder(n) << endl;
    cout << "test!!!" << endl;
    system("pause");
    return 0;
}