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

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k >= s.size())
            return s.size();
        int i = 0, j = 0, idx, maxc = 0, ans = 0;
        vector<int> count(26,0);
        while(j < s.size())
        {
            idx = s[j++]-'A';
            count[idx]++;
            if(maxc < count[idx])
            //只有新加入的字符的个数大于历史重复字符最高数时，才能更新答案
                maxc = count[idx];
            if(j-i-maxc <= k)//需要替换的个数
                ans = max(ans, j-i);
            else
                count[s[i++]-'A']--;
        }
        return ans;
    }
};