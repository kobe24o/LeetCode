#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size(), i, k, n, lv = 0;
        unordered_map<string,int> m;
        for(i = 0; i < len; ++i)
        	m[wordList[i]] = i;
        if(m.find(endWord) == m.end())
        	return 0;
        bool visited[len] = {false};
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
	        	{
                    str = q.front();
                    for(k = 1; k <= 25; ++k)
                    {
    	        		str[i] += 1;
    	        		if(str[i] > 'z')
    	        			str[i] = 'a';
    	        		if(m.find(str) != m.end() && !visited[m[str]])
    	        		{
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
	vector<string> v = {"hot","dot","dog","lot","log","cog"};
	s.ladderLength("hit","cog",v);
}