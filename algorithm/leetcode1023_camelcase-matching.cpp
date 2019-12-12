class Solution {
	int i, j, ni, nj;
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        nj = pattern.size();
        vector<bool> ans;
        for(auto& str : queries)
        	ans.push_back(match(str,pattern));
        return ans;
    }

    bool match(string& str, string& pattern)
    {
    	i=j=0;
    	ni = str.size();
    	while(i < ni && j < nj)
    	{
    		if(str[i]==pattern[j])
    		{
    			i++,j++;
    		}
    		else
    		{
    			if(isupper(str[i]))
    				return false;
    			else
    				i++;
    		}
    	}
    	if(i < ni)
    	{
    		while(i < ni)
    			if(isupper(str[i++]))
    				return false;
    	}
    	if(j < nj)
    		return false;
    	return true;
    }
};