class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> m;
        int sum;
        for(int i = 1; i <= n; ++i)
        {
            sum = cal(i);
            m[sum]++;
        }
        int maxlen = 0, count = 0;
        for(auto mi : m)
        {
            if(mi.second > maxlen)
            {
                maxlen = mi.second;
                count = 1;
            }
            else if(mi.second == maxlen)
                count++;
        }
        return count;
    }
    int cal(int i)
    {
        int sum = 0;
        while(i)
        {
            sum += i%10;
            i /= 10;
        }
        return sum;
    }
};