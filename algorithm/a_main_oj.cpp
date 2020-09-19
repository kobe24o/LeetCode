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
# include<queue>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int paintingPlan(int n, int k) {
        int x, y, ans = 0;
        for(x = 0; x <= n; ++x)
        {
            for(y = 0; y <= n; ++y)
            {
                if((x+y)*n-x*y == k)
                {
                    ans += C(n,x)*C(n,y);
                }
            }
        }
        return ans;
    }
    int C(int n, int x)
    {
        int ans = 1, t = x, a = 1;
        while(t--)
        {
            ans *= n--;
            a *= x--;
        }
        return ans/a;
    }
};


int main()
{
    vector<int> l = {2,1};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{14,7,11},{11,14,5},{14,3,10}};
    Solution s;
    string str = "bacbdab";
    cout << s.paintingPlan(2,4) <<endl;
    //读出二进制文件中的内容并输出到显示器6

    return 0;
}


