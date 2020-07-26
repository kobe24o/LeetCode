class Solution {
public:
    int minFlips(string target) {
    	int s = 0, i = 0, n = target.size();
    	while(i < n && target[i]=='0')
    		i++;
    	char prev = '0';
    	for( ; i < n; ++i)
    	{
    		if(prev != target[i])
    			s++;
    		prev = target[i];
    	}
    	return s;
    }
};