class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return countDigit(high, d) - countDigit(low-1, d);
    }

    int countDigit(int n, int d) {
        if(n < 0)
            return 0;
        int high, cur, low;
        long sum = 0, i = 1;
        while(n/i)
        {
            high = n/(i*10);
            cur = n/i%10;
            low = n-n/i*i;
            if(cur < d)
                sum += high*i;
            else if(cur == d)
                sum += high*i+low+1;
            else
                sum += (high+1)*i;
            if(d == 0)//特殊情况，减掉当前以0开头的个数
                sum -= i;
            i *= 10;
        }
        return sum;
    }
};