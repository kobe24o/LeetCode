class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    	int ans = 0, n = items.size();
    	for(int i = 0; i < n; i++) {
    		if((ruleKey=="type" && ruleValue==items[i][0])
    			||(ruleKey=="color" && ruleValue==items[i][1])
    			||(ruleKey=="name" && ruleValue==items[i][2]))
    			ans++;
    	}
    	return ans;
    }
};