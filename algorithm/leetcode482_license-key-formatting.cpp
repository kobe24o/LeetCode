class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int count = 0;
        for(int i = S.size()-1; i >= 0; i--)
        {
        	if(S[i] == '-')
        		continue;
        	if(isdigit(S[i]) || isupper(S[i]))
        		ans.push_back(S[i]);
        	else
        		ans.push_back(toupper(S[i]));
    		count++;
    		if(i != 0 && count == K)
			{
				ans.push_back('-');
				count = 0;
			}
        }
        if(ans[ans.size()-1] == '-')
        	ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};