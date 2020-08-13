class Solution {
public:
    string minWindow(string S, string T) {
    	int i = 0, j = 0, minlen = INT_MAX;
    	int l = -1, r;
    	while(i < S.size())
    	{
    		if(S[i] == T[j])
    		{
    			j++;
    			if(j == T.size())//全部匹配了
    			{
    				r = i+1;
    				j--;
    				while(j >= 0)
    				{
    					while(S[i] != T[j])
    						i--;
    					i--;j--;
    				}
    				i++,j++;
    				if(r-i < minlen)
    				{
    					minlen = r - i;
    					l = i;
    				}
    			}
    		}
    		i++;
    	}
    	return l == -1 ? "" : S.substr(l,minlen);
    }
};