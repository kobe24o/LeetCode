class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int i = L, n, count, ans = 0;
        while(i <= R)
        {
        	n = i;
        	count = 0;
        	while(n)
        	{
        		n = n&(n-1);
        		++count;
        	}
        	++i;
        	if(primes.find(count) != primes.end())
        		++ans;
        }
        return ans;
    }
};