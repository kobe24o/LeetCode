class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> m;
        int maxcount = 0;
        for(int i = lowLimit; i <= highLimit; ++i)
        {
            int n = i, sum = 0;
            while(n)
            {
                sum += n%10;
                n /= 10;
            }
            if(++m[sum] > maxcount)
                maxcount = m[sum];
        }
        return maxcount;
    }
};