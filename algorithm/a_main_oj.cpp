#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
#include<algorithm>
using namespace std;
#include <string>     // std::string, std::stoi
#include <map>
#include<stack>

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    /**
     * @param heights: the heights of buildings.
     * @param k: the vision.
     * @param x: the energy to spend of the first action.
     * @param y: the energy to spend of the second action.
     * @return: the minimal energy to spend.
     */
    long long shuttleInBuildings(vector<int> &heights, int k, int x, int y) {
        // write your code here.
        int n = heights.size(), i, j, K;
        stack<int> s;
        vector<int> rightTall(n, -1);
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && heights[s.top()] <= heights[i])
                s.pop();
            if(!s.empty() && s.top()-i <= k)
                rightTall[i] = s.top();
            s.push(i);
        }
        vector<long long> dp(n, LONG_LONG_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == LONG_LONG_MAX)
                continue;
            if(i+1 < n)
                dp[i+1] = min(dp[i+1], dp[i]+y);
            if(i+2 < n)
                dp[i+2] = min(dp[i+2], dp[i]+y);
            if(rightTall[i] != -1)
                dp[rightTall[i]] = min(dp[rightTall[i]], dp[i]+x);
        }
        return dp[n-1];
    }
};
int main()
{
    vector<int> l = {1,5,4,3,3,5};
    Solution s;
    string str = "bacbdab";
    cout << s.shuttleInBuildings(l, 3,10, 6)<<endl;
    //读出二进制文件中的内容并输出到显示器6
    system("pause");
    return 0;
}


