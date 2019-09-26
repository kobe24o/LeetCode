class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
    	unordered_map<char,int> m;
    	int i,j,len;
    	bool small;
        for(i = 0; i < order.size(); ++i)
        {
        	m[order[i]] = i;
        }
        for(i = 1; i < words.size(); ++i)
        {
        	small = false;
        	len = min(words[i-1].size(),words[i].size());
        	for(j = 0; j < len; ++j)
        	{
        		if(m[words[i-1][j]] < m[words[i][j]])
        		{
        			small = true;
        			break;
        		}
        		else if(m[words[i-1][j]] > m[words[i][j]])
        			return false;
        	}
        	if(!small && words[i-1].size() > len)
        		return false;
        }
        return true;
    }
};