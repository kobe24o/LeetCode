#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
        int m = 0;
        while(dp[K][m] < N) 
        {
            m++;
            cout << "m: " << m ;
            for(int k = 1; k <= K; ++k)
            {
            	dp[k][m] = dp[k-1][m-1] + dp[k][m-1] + 1;
            	cout << "k: " << k << endl;
            	cout << "dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1" << endl;
            	cout << dp[m][k] << " " << dp[m-1][k-1] << " " << dp[m-1][k] << endl;
            }
        }
        return m;   
    }
};
int main()
{
	Solution s;
	s.superEggDrop(3,14);
	return 0;
}