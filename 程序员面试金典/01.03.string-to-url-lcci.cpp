class Solution {
public:
    string replaceSpaces(string S, int length) {
        int i, j, count = 0;
    	for(i = 0; i < length; ++i)
    	{
    		if(S[i] == ' ')
        		count++;
    	}
        int len = length-count+3*count;
        string ans(len,' ');
        for(i = 0, j = 0; i < length; ++i,++j)
        {
            if(S[i] != ' ')
                ans[j] = S[i];
            else
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j]   = '0';
            }
        }
    	return ans;
    }
};