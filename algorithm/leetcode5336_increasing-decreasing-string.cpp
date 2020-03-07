class Solution {
public:
    string sortString(string s) {
        int m[26] = {0}, sum = 0, i;
        for(auto& ch : s)
        {
            m[ch-'a']++;
            sum++;
        }
        string ans;
        while(sum)
        {
            for(i = 0; i < 26; i++)
            {
                if(m[i])
                {
                    ans.push_back(i+'a');
                    sum--;
                    m[i]--;
                }   
            }
            for(i = 25; i >= 0; i--)
            {
                if(m[i])
                {
                    ans.push_back(i+'a');
                    sum--;
                    m[i]--;
                }   
            }
        }
        return ans;
    }
};
