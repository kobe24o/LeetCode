class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
    	vector<string> ans;
    	string temp;
    	for(int i = 1; i < s.size(); ++i)
    	{
    		if(s[i-1]==s[i] && s[i]=='+')
    		{
    			temp = s;
    			temp[i-1] = temp[i] = '-';
    			ans.push_back(temp);
    		}
    	}
    	return ans;
    }
};