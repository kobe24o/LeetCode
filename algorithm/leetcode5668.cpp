class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size(), maxlen = 0;
        string ans;
        for(int i = 0; i < n; ++i)
        {
            vector<int> ct1(26), ct2(26);
            for(int j = i; j < n; ++j)
            {
                if(isupper(s[j]))
                    ct2[s[j]-'A']++;
                else    
                    ct1[s[j]-'a']++;
                if(ok(ct1, ct2) && j-i+1 > maxlen)
                {
                    maxlen = j-i+1;
                    ans = s.substr(i, maxlen);
                }
            }
        }
        return ans;
    }
    bool ok(vector<int>& ct1, vector<int>& ct2)
    {
        int count = 0;
        for(int i = 0; i < 26; ++i)
        {
            if((ct1[i]==0 && ct2[i]!=0) || (ct1[i]!=0 && ct2[i]==0))
                return false;
            else if(ct1[i]>0 && ct2[i]>0)
                count++;
        }
        return count>0;
    }
};