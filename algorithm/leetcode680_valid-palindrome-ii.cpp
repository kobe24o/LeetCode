class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size() <= 2)
        	return true;
        int i = 0, j = s.size()-1;
        while(i < j)
        {
        	if(s[i] == s[j])
        		i++,j--;
        	else
    			return (valid(s,i+1,j) || valid(s,i,j-1));
        }
        return true;
    }
    bool valid(string &s, int i, int j)
    {
    	if(i > j)
    		return false;
    	while(i <= j)
    	{
    		if(s[i] == s[j])
    			i++,j--;
    		else
    			return false;
    	}
    	return true;
    }
};