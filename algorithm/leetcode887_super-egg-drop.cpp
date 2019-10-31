#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        int m, k;
        for(m = 1; m <= N; m++) 
        {
            for(k = 1; k <= K; k++) 
            {
                dp[k][m] = dp[k][m-1] + dp[k-1][m-1] + 1;
                if(dp[k][m] >= N)
                    return m;
            }
        }
        return N; 
    }
};
int main()
{
	Solution s;
	s.superEggDrop(3,14);
	return 0;
}