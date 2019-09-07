#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int numPrimeArrangements(int n) {
        if(n == 1)
            return 1;
        int count = 0, i, j;
        unsigned long long ans = 1;
        bool flag;
        for(i = 2; i <= n; ++i)
        {
            flag = true;
            for(j = 2; j <= sqrt(i); ++j)
            {
                if(i%j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ++count;
        }
        n = n-count;
        while(n)
        {
            ans *= n--;
            ans %= (long long)(1e9 + 7);
        }
        while(count)
        {
            ans *= count--;
            ans %= (long long)(1e9 + 7);
        }
        return ans%(1000000007);
    }
};

int main()
{
	Solution s;
	cout << s.numPrimeArrangements(100);
	return 0;
}