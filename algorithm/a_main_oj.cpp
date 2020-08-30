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
    int getMaxLen(vector<int>& nums) {
    	int maxlen = 0, i, n = nums.size(), p = 1;
    	int posneg[2] = {-1, -1};//记录第一次正或者负出现的位置
    	for(int i = 0; i < n; ++i)
    	{
    		if(nums[i] > 0)
    		{
    			if(posneg[0] == -1)//第一次正数
    				posneg[0] = i;
    		}
    		else if(nums[i] < 0)
    		{
    			p *= -1;//乘积变号
    			if(posneg[1] == -1)//第一次负数
    				posneg[1] = i;
    		}
    		else//乘积为0
    		{
    			posneg[0] = posneg[1] = -1;
                p = 1;
    		}
			if(p > 0)
				maxlen = max(maxlen, i-posneg[0]+1);
			else if(p < 0)
				maxlen = max(maxlen, i-posneg[1]);
    	}
    	return maxlen;
    }
};
int main()
{
    vector<int> l = {-1,-2,-3,0,1};
    Solution s;
    string str = "bacbdab";
    cout << s.getMaxLen(l) <<endl;
    //读出二进制文件中的内容并输出到显示器6
    system("pause");
    return 0;
}


