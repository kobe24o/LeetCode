#include <unordered_map>
#include <string>
#include <queue>
#include <climits>

using namespace std;
class Solution {
    unordered_map<string,int> m;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int minLen = ladderLength(beginWord, endWord, wordList);
        if(minLen == 0)
            return {};
        vector<string> path;
        vector<vector<string>> ans;
        int N = wordList.size();
        bool visited[N] = { false };
        path.push_back(beginWord);
        dfs(beginWord, endWord, wordList, path, ans, 1, minLen, visited);
        return ans;
    }

    void dfs(string &beginWord, string &endWord, vector<string>& wordList, vector<string> path, vector<vector<string>> &ans, int len, int &minLen, bool *visited) 
    {
        if(len == minLen)
        {
            if(path.back() == endWord)
                ans.push_back(path);
            return;
        }
        for(int i = 0; i < beginWord.size(); ++i)
        {
            string str = path.back();
            for(int k = 1; k <= 25; ++k)
            {
                str[i] += 1;
                if(str[i] > 'z')
                    str[i] = 'a';
                if(m.find(str) != m.end() && !visited[m[str]])
                {   
                    path.push_back(str);
                    visited[m[str]] = true;
                    dfs(beginWord, endWord, wordList, path, ans, len+1,minLen,visited);
                    path.pop_back();
                    visited[m[str]] = false;
                }
            }
        }
    }

    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        for(auto it = wordList.begin(); it != wordList.end(); ++it)
            if(*it == beginWord)
            {
                swap(*it,wordList.back());
                wordList.pop_back();
            }
        int len = wordList.size(), i, k, n, lv = 0;
        bool visited[len] = {false};
        for(i = 0; i < len; ++i)
            m[wordList[i]] = i;
        if(m.find(endWord) == m.end())
            return 0;
        queue<string> q;
        string str;
        q.push(beginWord);
        while(!q.empty())
        {
            lv++;
            n = q.size();
            while(n--)
            {
                for(i = 0; i < beginWord.size(); ++i)
                {//对每个单词的每个字符进行改变
                    str = q.front();
                    for(k = 1; k <= 25; ++k)
                    {
                        str[i] += 1;
                        if(str[i] > 'z')
                            str[i] = 'a';
                        if(m.find(str) != m.end() && !visited[m[str]])
                        {   //在集合中，且没有访问的
                            q.push(str);
                            visited[m[str]] = true;
                            if(str == endWord)
                                return lv+1;
                        }
                    }
                }
                q.pop();
            }
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<string> v = {"ts","sc","ph","ca","jr","hf","to","if","ha","is","io","cf","ta"};
    s.findLadders("ta","if",v);
}