class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dpa(n, 0), dpb(n, 0);
        if(s[0] == 'a')
            dpb[0] = 1;//以 b 结尾需要删除1次
        else
            dpa[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == 'a')
            {
                dpa[i] = dpa[i-1];
                dpb[i] = min(dpa[i-1]+1, dpb[i-1]+1);
            }
            else
            {
                dpa[i] = dpa[i-1]+1;
                dpb[i] = min(dpa[i-1], dpb[i-1]);
            }
        }
        return min(dpa[n-1], dpb[n-1]);
    }
};