class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string str;
        bt(S, str, ans, 0);
        return ans;
    }
    void bt(string &S, string str, vector<string> &ans, int i)
    {
    	if(i == S.size())
    	{
    		ans.push_back(str);
    		return;
    	}
    	if(S[i] >= '0' && S[i] <= '9')
		{
			str.push_back(S[i]);
			bt(S, str, ans, i+1);
		}
		if(S[i] >= 'a' && S[i] <= 'z')
		{
			str.push_back(S[i]);
			bt(S, str, ans, i+1);
			str.pop_back();
			str.push_back(S[i]-32);
			bt(S, str, ans, i+1);
		}
		if(S[i] >= 'A' && S[i] <= 'Z')
		{
			str.push_back(S[i]);
			bt(S, str, ans, i+1);
			str.pop_back();
			str.push_back(S[i]+32);
			bt(S, str, ans, i+1);
		}
    }
};