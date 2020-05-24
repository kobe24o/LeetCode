class Solution {
public:
    int maxVowels(string s, int k) {
    	int count = 0, maxcount = 0, l = 0, r = 0;
    	while(r < k)
    	{
    		if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u')
    			count++;
    		r++;
    	}
    	maxcount = count;
    	for( ; r < s.size(); ++l,++r)
    	{
    		if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u')
    			count++;
    		if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u')
    			count--;
    		maxcount = max(maxcount, count);
    	}
    	return maxcount;
    }
};