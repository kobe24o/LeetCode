class Solution {
    unordered_map<string,unordered_map<string,bool>> m;
public:
    bool isScramble(string s1, string s2) {
        if(m.count(s1) && m[s1].count(s2))
            return m[s1][s2];
        if(s1 == s2) return m[s1][s2]=true;
        for(int len = 1; len < s1.size(); ++len)
        {
            string s1a = s1.substr(0,len), s1b = s1.substr(len);
            string s2a = s2.substr(0,len), s2b = s2.substr(len);
            string s2a_ = s2.substr(0,s2.size()-len), s2b_ = s2.substr(s2.size()-len);
            if(isScramble(s1a, s2a) && isScramble(s1b, s2b))
                return m[s1][s2] = true;
            if(isScramble(s1a, s2b_) && isScramble(s1b, s2a_))
                return m[s1][s2] = true;
        }
        return m[s1][s2] = false;
    }
};