class Solution {
public:
    int numSub(string s) {
        int i,j,n=s.size(),sum = 0, mod = int(1e9+7);
        for(i = 0; i < n; ++i)
        {
            if(s[i]=='1')
            {
                j = i;
                while(j < n && s[j]=='1')
                {
                    j++; 
                }
                long long n = j-i;
                sum = (sum+((n*(n+1)/2)%mod))%mod;
                i = j-1;
            }
        }
        return sum%mod;
    }
};
