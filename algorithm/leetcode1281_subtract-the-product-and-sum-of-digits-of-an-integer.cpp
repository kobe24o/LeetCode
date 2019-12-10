class Solution {
public:
    int subtractProductAndSum(int n) {
        int bit, product = 1, ans = 0;
        while(n)
        {
            bit = n%10;
            ans -= bit;
            product *= bit;
            n /= 10;
        }
        ans += product;
        return ans;
    }
};