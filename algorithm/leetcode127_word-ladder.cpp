#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         int len = wordList.size(), i, k, n, lv = 0;
//         unordered_map<string,int> m;
//         for(i = 0; i < len; ++i)
//         	m[wordList[i]] = i;
//         if(m.find(endWord) == m.end())
//         	return 0;
//         bool visited[len] = {false};
//         queue<string> q;
//         string str;
//         q.push(beginWord);
//         while(!q.empty())
//         {
//         	lv++;
//         	n = q.size();
//         	while(n--)
//         	{
// 	        	for(i = 0; i < beginWord.size(); ++i)
// 	        	{
//                     str = q.front();
//                     for(k = 1; k <= 25; ++k)
//                     {
//     	        		str[i] += 1;
//     	        		if(str[i] > 'z')
//     	        			str[i] = 'a';
//     	        		if(m.find(str) != m.end() && !visited[m[str]])
//     	        		{
//     	        			q.push(str);
//     	        			visited[m[str]] = true;
//     	        			if(str == endWord)
//             					return lv+1;
//     	        		}
//                     }
// 	        	}
// 	        	q.pop();
// 	        }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size(), wlen = beginWord.size(), i, k, n, n1, n2, flag, lv = 0;
        unordered_map<string,int> m;
        vector<int> visited(len,0);
        bool beginWordInList = false;
        for(i = 0; i < len; ++i)
        {
            m[wordList[i]] = i;
            if(wordList[i] == beginWord)
            {
                visited[i] = 1;
                beginWordInList = true;
            }
        }
        if(!beginWordInList)
        {
            visited.push_back(1);
            m[beginWord] = len;
        }
        if(m.find(endWord) == m.end())
            return 0;
        queue<string> q1, q2;
        string str;
        q1.push(beginWord);
        q2.push(endWord);
        visited[m[endWord]] = 2;
        while(!q1.empty() && !q2.empty())
        {
            lv++;
            n1 = q1.size();
            n2 = q2.size();
            queue<string> &Q = n1<n2 ? q1 : q2;
            flag = n1<n2 ? 1 : 2;
            n = Q.size();
            while(n--)
            {
                for(i = 0; i < wlen; ++i)
                {
                    str = Q.front();
                    for(k = 1; k <= 25; ++k)
                    {
                        str[i] += 1;
                        if(str[i] > 'z')
                            str[i] = 'a';
                        if(m.find(str) != m.end() && visited[m[str]] != flag)
                        {
                            Q.push(str);
                            visited[m[str]] += flag;
                            if(visited[m[str]] == 3)
                                return lv+1;
                        }
                    }
                }
                Q.pop();
            }
        }
        return 0;
    }
};
int main()
{
	Solution s;
	vector<string> v = {"cog"};
	s.ladderLength("hog","cog",v);
}