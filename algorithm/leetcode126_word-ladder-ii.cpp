#include <unordered_map>
#include <string>
#include <queue>
#include <climits>

using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size(), i, k, n, lv = 0, minLv = INT_MAX, j, ansLen;
        unordered_map<string,int> m;
        bool visited[len] = {false};
        for(i = 0; i < len; ++i)
        {
            m[wordList[i]] = i;
            if(wordList[i] == beginWord)
                visited[i] = true;
        }
        if(m.find(endWord) == m.end())
        	return {};
        queue<string> q;
        string str;
        vector<vector<string>> ans;
        vector<string> path;
        path.push_back(beginWord);
        ans.push_back(path);
        q.push(beginWord);
        while(!q.empty())
        {
        	lv++;
        	n = q.size();
            ansLen = ans.size();
        	while(n--)
        	{
	        	for(i = 0; i < beginWord.size(); ++i)
	        	{
                    str = q.front();
                    for(k = 1; k <= 25; ++k)
                    {
    	        		str[i] += 1;
    	        		if(str[i] > 'z')
    	        			str[i] = 'a';
    	        		if(m.find(str) != m.end() && !visited[m[str]])
    	        		{
    	        		    // ansLen = ans.size();
                            for(j = 0; j < ansLen; ++j)
                            {
                                if(ans[j].back() == q.front())
                                {
                                    path = ans[j];
                                    path.push_back(str);
                                    ans.push_back(path);
                                }
                            }
    	        			q.push(str);
    	        			visited[m[str]] = true;
    	        			if(str == endWord)
                            {
                                if(lv+1 < minLv)
                                    minLv = lv+1; 
                            }
    	        		}
                    }
	        	}
	        	q.pop();
	        }
            ans.erase(ans.begin(), ans.begin()+ansLen);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit","cog",v);
}