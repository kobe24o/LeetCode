#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
    	if(p.size() <= 2)
    		return p.size();
        int i, j, k, count, maxCount = 2;
        long dx, dy, dX, dY;
        for(i = 0; i < p.size()-1; ++i)
        {
        	j = i+1;
        	count = 1;
        	dx = 0;
			dy = 0;
        	while(j < p.size() && dx==0 && dy==0)
        	{//找到不为重合的点，计算dx，dy
        		dx = p[j][0]-p[i][0];
    			dy = p[j][1]-p[i][1];
                j++;
        		count++;
        	}
        	for(k = 0; k < p.size(); ++k)
        	{
        		if(k >= i && k <= j)
        			continue;//重复的点不再考察
        		dX = p[k][0]-p[i][0];
        		dY = p[k][1]-p[i][1];
        		if(dY*dx == dy*dX)//与选定的直线斜率相同
        		{
        			count++;
        			if(count > maxCount)
        				maxCount = count;
        		}
        	}
        }
        return maxCount;
    }
};

int main()
{
	vector<vector<int>> v = {{1,1},{1,1},{1,1}};
	Solution s;
	cout << s.maxPoints(v);
}