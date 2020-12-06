class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, mod = 1e9+7;
        vector<int> plus(32);
        for(int i = 1; i < 32; ++i)
            plus[i] = 1<<i;
        int bit;
        for(int i = 1; i <= n; ++i) 
        {
            bit = count(i);
            ans = (ans*plus[bit] + i)%mod;
        }
        return ans;
    }
    int count(int x)
    {
        int num = 1, count = 1;
        while(x > num)
        {
            num = num + (1 << count);
            count++;
        }
        return count;
    }
};