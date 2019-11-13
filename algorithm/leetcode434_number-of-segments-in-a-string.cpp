class Solution {
public:
    int countSegments(string s) {
        s.push_back(' ');//考虑边界可以简化很多
        int cnt = 0, i;
        for(i = 0; i < s.size() - 1; i++) 
        {
            if(s[i] != ' ' && s[i+1] == ' ')
                cnt++;
        }
        return cnt;
    }
};