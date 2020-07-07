class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size(), i = 0, j = 0, count = 0;
        if(abs(m-n)>1) return false;
        if(m==n)
        {
        	while(i < m)
	    	{
	    		if(s[i] != t[i])
	    			count++;
	    		if(count > 1)
	    			return false;
                i++;
	    	}
        }
        else//数量相差一个
        {
        	count = 1;
        	if(m > n)
        		swap(s,t);// 让 s 短
        	bool founddiff = false;
        	for(i = 0; i < m; i++)
        	{
        		if(!founddiff && s[i] != t[i])
    				founddiff = true;
        		if(founddiff && s[i] != t[i+1])
        			count++;
        		if(count > 1)
        			return false;
        	}
        }
        return count==1;
    }
};