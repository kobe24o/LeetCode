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
     * @param a: Left margin
     * @param b: Right margin
     * @return: return the greatest common multiple
     */
    long long greatestcommonmultiple(int a, int b) {
        // write your code here
        int lcm3 = lcm_(b,b-1,b-2);
        int lcm_3_1 = 0, lcm4 = 0, lcm5 = 0;
        if(b-3 >= a)
            int lcm_3_1 = lcm_(b-3, b-1, b-2);
        if(b%2==1)
            lcm4 = lcm_(b,b-1,b-2);
        if(b%2==0 && b-3>=a)
            lcm5 = lcm_((b),(b-1),(b-3));
        return max(lcm3, max(lcm_3_1,max(lcm4, lcm5)));
    }
    int lcm(int a, int b)
    {
        return a*b/__gcd(a,b);
    }
    int lcm_(int a, int b, int c)
    {
        int l = lcm(a,b);
        return lcm(c, l);
    }
};

int main()
{
    vector<int> l = {2,1};
    vector<vector<int>> t = {{14,2,11},{11,14,5},{14,3,10}};
    vector<vector<int>> t1 = {{14,7,11},{11,14,5},{14,3,10}};
    Solution s;
    string str = "bacbdab";
    cout << s.lcm_(5,7,6) <<endl;
    //读出二进制文件中的内容并输出到显示器6

    return 0;
}


