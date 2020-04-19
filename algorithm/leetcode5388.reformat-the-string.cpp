class Solution {
public:
    string reformat(string s) {
    	int count[36] = {0}, i, j, k, a=0, n=0;
    	for(i = 0; i < s.size(); ++i)
    	{
    		if(isdigit(s[i]))
    			count[s[i]-'0'+26]++, n++;
    		else
    			count[s[i]-'a']++, a++;
    	}
    	if(abs(a-n) > 1)
    		return "";
    	if(a >= n)
    	{
    		k = 0;
    		for(i = 0; i < 26; ++i)
    		{
    			while(count[i]--)
    			{
    				s[k] = i+'a';
    				k += 2;
    			}
    		}
    		k = 1;
    		for(i = 26; i < 36; ++i)
    		{
    			while(count[i]--)
    			{
    				s[k] = i+'0'-26;
    				k += 2;
    			}
    		}
    	}
    	else
    	{
    		k = 0;
    		for(i = 26; i < 36; ++i)
    		{
    			while(count[i]--)
    			{
    				s[k] = i+'0'-26;
    				k += 2;
    			}
    		}
    		k = 1;
    		for(i = 0; i < 26; ++i)
    		{
    			while(count[i]--)
    			{
    				s[k] = i+'a';
    				k += 2;
    			}
    		}
    	}
    	return s;
    }
};