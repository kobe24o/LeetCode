class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k >= s.size())
        	return s.size();
        int i = 0, j = 0, ans = 0;
        vector<int> count(26,0);
        while(j < k)
        	count[s[j++]-'A']++;
        while(j < s.size())
        {
        	count[s[j++]-'A']++;
        	if(j-i-*max_element(count.begin(),count.end()) <= k)//需要替换的个数
        		ans = max(ans, j-i);
        	else
        		count[s[i++]-'A']--;
        }
        return ans;
    }
};