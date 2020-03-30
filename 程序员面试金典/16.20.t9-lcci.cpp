class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        string key[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        int i;
        bool ok;
        for(auto& w : words)
        {
        	ok = true;
        	for(i = 0; i < w.size(); ++i)
        	{
        		if(key[num[i]-'0'].find(w[i]) == string::npos)
        		{
        			ok = false;
        			break;
        		}
        	}
        	if(ok)
        		ans.push_back(w);
        }
        return ans;
    }
};