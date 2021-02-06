class Solution {
public:
    int minimumLength(string s) {
    	int i = 0, j = s.size()-1;
    	char l, r;
    	while(i < j && s[i] == s[j])
    	{
    		l = s[i], r = s[j];
    		while(i < j && s[i] == l)
    			i++;
    		while(i-1 < j && s[j] == r)
    			j--;
    	}
    	return j-i+1;
    }
};
