class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> allchar;
        for(string& w : words)
        {
        	for(char ch : w)
        		allchar.insert(ch);
        }//记下所有的字符
        unordered_map<char,int> indegree;
        unordered_map<char,unordered_set<char>> graph;
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
                    if(!graph.count(words[i-1][j]) || !graph[words[i-1][j]].count(words[i][j]))
        			{   //防止重复添加同一条边 "za","zb","ca","cb"
                        graph[words[i-1][j]].insert(words[i][j]);
                        indegree[words[i][j]]++;
                        indegree[words[i-1][j]] += 0;
                    }
        			break;
        		}
        	}
        	if(j == n && n1 > n2)
        		return "";//前面相等，前者长不行
        }
        queue<char> q;
        for(auto it = indegree.begin(); it != indegree.end(); ++it)
        {
        	if(it->second == 0)
        		q.push(it->first);
        }
        string ans;
        while(!q.empty())
        {
        	char ch = q.front();
        	allchar.erase(ch);
        	q.pop();
        	ans += ch;
        	for(auto it = graph[ch].begin(); it != graph[ch].end(); ++it)
        	{
        		if(--indegree[*it] == 0)
        			q.push(*it);
        	}
        }
        if(ans.size() != indegree.size())
        	return "";
        while(allchar.size())
        {
        	ans += *allchar.begin();
        	allchar.erase(allchar.begin());
        }
        return ans;
    }	
};