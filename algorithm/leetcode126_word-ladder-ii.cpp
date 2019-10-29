class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size(), i, k, n, lv = 0, minLv = INT_MAX, j;
        unordered_map<string,int> m;
        for(i = 0; i < len; ++i)
        {
            m[wordList[i]] = i;
            if(wordList[i] == beginWord)
                visited[i] = true;
        }
        if(m.find(endWord) == m.end())
        	return {};
        bool visited[len] = {false};
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
                            for(auto it = ans.begin(); it != ans.end(); ++it)
                            {
                                if(it->back() == q.front())
                                    it->push_back(str);
                                if(it->size() > minLv)
                                    ans.erase(it);
                            }
    	        			q.push(str);
    	        			visited[m[str]] = true;
    	        			if(str == endWord)
                            {
                                lv++;
                                if(lv < minLv)
                                    minLv = lv; 
                            }
    	        		}
                    }
	        	}
	        	q.pop();
	        }
        }
        return ans;
    }
};