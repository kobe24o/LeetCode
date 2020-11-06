class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, -1);
        for(int i = 0; i < s.size(); ++i)
            last[s[i]-'a'] = i;//记录字符出现的最后的位置
        string ans;
        unordered_set<char> set;
        for(int i = 0; i < s.size(); ++i)
        {
            if(set.count(s[i]))
                continue;
            while(!ans.empty() && ans.back() > s[i] && last[ans.back()-'a'] > i)
            {
                set.erase(ans.back());
                ans.pop_back();
            }
            set.insert(s[i]);
            ans += s[i];
        }
        return ans;
    }
};