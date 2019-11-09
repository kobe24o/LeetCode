class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, prev = 0, len = 0;
        bool clear = false;
        for(i = 0; i < s.size(); ++i)
        {
        	if(s[i] == ' ')
        	{
        		if(!clear)
        		{
        			prev = len;
        			len = 0;
        			clear = true;
        		}
        	}
        	else
        	{
        		len++;
        		if(clear)
        			clear = false;
            }
        }
        if(len == 0)
        	return prev;
        return len;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, len = 0;
        for(i = s.size()-1; i >= 0; --i)
        {
        	if(s[i] != ' ')
        	{
        		len++;
        	}
        	else
        	{
        		if(len != 0)
        			return len;
            }
        }
        return len;
    }
};