class Solution {
public:
    bool validWordSquare(vector<string>& words) {
    	int m = words.size(), i, j;
    	for(i = 0; i < m; ++i)
    	{
    		if(words[i].size() > m)
    			return false;
    		if(words[i].size() < m)
    			words[i] += string(m-words[i].size(),' ');
    	}
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < m; ++j)
			{
				if(words[i][j] != words[j][i])
					return false;
			}
		}
		return true;
    }
};