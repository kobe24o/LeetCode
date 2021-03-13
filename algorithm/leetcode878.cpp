class Solution {
public:
    int lcmab;//最小公倍数
    int nthMagicalNumber(int N, int A, int B) {
        long long lo = 2, hi = 1e15, ans, mid, mod = 1e9+7, num;
        lcmab = A/__gcd(A,B)*B;// 最小公倍数 = A*B/最大公约数(A,B)
        while(lo <= hi) 
        {
            mid = lo+((hi-lo)>>1);
            num = ct(mid,A,B);// mid 包含多少个 神奇数字
            if(num >= N)
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans%mod;
    }
    long long ct(long long n, int A, int B) {
        return n/A + n/B - n/lcmab;
    }
};