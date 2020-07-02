class Solution {
public:
    int countLetters(string s) {
    	int i, count = 0, previd = 0;
    	char prev = s[0];
        for(i = 0; i < s.size(); ++i)
        {
        	if(s[i]==prev)
        		count += i-previd+1;
        	else
        	{
        		prev = s[i];
                count += 1;
        		previd = i;
        	}
        }
        return count;
    }
};