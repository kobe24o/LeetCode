class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size())
            return false;
        int diff;
        vector<int> count(26, 0);
        for(int i = 0; i < s.size();  ++i)
        {
            if(s[i] == t[i])
                continue;
            if(s[i] < t[i])
                diff = t[i]-s[i];
            else if(s[i] > t[i])
                diff = 'z'-s[i]+t[i]-'a'+1;
            count[diff]++;
        }
        for(int  i = 0; i < 26; ++i)
        {
            if((count[i]-1)*26+i > k)
                return false;
        }
        return true;
    }
};