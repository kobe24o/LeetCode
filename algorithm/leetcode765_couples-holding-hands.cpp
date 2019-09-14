#include<unordered_map>
#include<vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int m[row.size()];
        int i, count = 0;
        for(i = 0; i < row.size(); ++i)
        {
        	m[row[i]] = i;
        }
        for(i = 0; i < row.size(); ++i)
        {
        	if(row[i]%2 == 0)//偶数号，其对象是+1号
        	{
        		if(row[i+1] == row[i]+1)//旁边就是
        			++i;//不用调整，跳过
        		else//旁边不是
        		{
                    m[row[i+1]] = m[row[i]+1];//下面要挪动旁边的人，其序号更新
        			swap(row[i+1],row[m[row[i]+1]]);
        			++i;
        			++count;
        		}
        	}
        	else//奇数号，对象是-1号
        	{
        		if(row[i+1] == row[i]-1)
        			++i;
        		else
        		{
                    m[row[i+1]] = m[row[i]-1];//序号更新
        			swap(row[i+1],row[m[row[i]-1]]);
        			++i;
        			++count;
        		}
        	}
        }
        return count;
    }
};
int main()
{
    vector<int> v = {0,2,4,6,7,1,3,5};
    Solution s;
    cout << s.minSwapsCouples(v);
    return 0;
}