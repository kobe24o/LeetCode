class Solution {
public:
    int maxScore(string s) {
        vector<int> left0(2*s.size()-1,0);
        vector<int> right1(2*s.size()-1,0);
        int i, n = s.size();
        left0[0] = s[0]=='0' ? 1 : 0;
        for(i = 1; i < n; ++i)
            left0[2*i] = s[i]=='0'? left0[2*i-2]+1 : left0[2*i-2];
        right1[2*n-2] = s[n-1]=='1' ? 1 : 0;
        for(i = n-2; i >= 0; --i)
            right1[2*i] = s[i]=='1'? right1[2*i+2]+1 : right1[2*i+2];
        int maxsc = 0;
        for(i = 1; i < 2*n-2; i+=2)
            maxsc = max(maxsc, left0[i-1]+right1[i+1]);
        return maxsc;
    }
};
class Solution {
public:
    int maxScore(string s) {
        int i, one = 0, maxs = 0, zero = 0;
        for(i = 0; i < s.size(); ++i)
        {
            if(s[i]=='1')
                one++;
        }
        for(i = 0; i < s.size()-1; ++i)
        {
            // maxs = max(maxs,zero+one);
            if(s[i]=='0')
                zero++;
            else
                one--;
            maxs = max(maxs,zero+one);
        }
        return maxs;
    }
};