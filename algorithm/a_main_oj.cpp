#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
#include <string>     // std::string, std::stoi
#include <map>
#include<stack>
# include<queue>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0, i;
        long long all = 0;
        for(i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i])%p;
            all += nums[i];
        }
        if(sum == 0)
            return 0;
        if(all < p)
            return -1;
        int s = 0, prev = -1, minlen = INT_MAX;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            s = (s + nums[i])%p;
            if(m.find((s+sum)%p) != m.end())
            {
                minlen = min(minlen, i-m[(s+sum)%p]);
            }
            if(m.find((s-sum+p)%p) != m.end())
            {
                minlen = min(minlen, i-m[(s-sum+p)%p]);
            }
            m[s] = i;
        }
        return minlen;
    }
};


int main()
{
    vector<int> l = {6,3,5,2};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{14,7,11},{11,14,5},{14,3,10}};
    Solution s;
    string str = "bacbdab";
    cout << s.minSubarray(l, 9) <<endl;
    //读出二进制文件中的内容并输出到显示器6

    return 0;
}


