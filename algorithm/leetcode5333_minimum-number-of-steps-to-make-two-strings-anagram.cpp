class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26, 0);
        for(auto& ch : s)
        	count[ch-'a']++;
        for(auto& ch : t)
        	count[ch-'a']--;
        int n = 0, i;
        for(i = 0; i < 26; i++)
        	if(count[i] < 0)//不存在的，需要变的
        		n += count[i];
    	return -n;
    }
};