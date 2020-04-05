class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;
        int count[26] = {0};
        for(int i = 0; i < s.size(); ++i)
            count[s[i]-'a']++;
        int odd = 0;
        for(int i = 0; i < 26; ++i)
        {
            if(count[i]%2 == 1)
                odd++;
        }       
        return odd <= k;
    }
};