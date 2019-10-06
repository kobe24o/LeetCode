class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
        	return 0;
        int i = 0, j = 0, i0;
        for(i = 0; i < haystack.size(); ++i)
        {
        	for(i0 = i,j = 0; i0 < haystack.size() && j < needle.size(); ++j)
        	{
        		if(haystack[i0] == needle[j])
        		{
        			++i0;
        			if(j == needle.size() -1)
        				return i;
                }
        		else
        			break;
        	}
        }
        return -1;
    }
};