class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
    	sort(words.begin(), words.end(),[&](auto a, auto b){
    		return a.size() < b.size();
    	});
    	vector<string> ans;
    	int i, j;
    	for(i = 0; i < words.size()-1; ++i)
    	{
    		for(j = i+1; j < words.size(); ++j)
    		{
    			if(words[j].find(words[i]) != string::npos)
    			{
    				ans.push_back(words[i]);
    				break;
    			}
    		}
    	}
    	return ans;
    }
};