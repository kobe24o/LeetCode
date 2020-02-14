class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int l = 1, r = 0, sum = 0, i;
        while(sum < target)
        {	//先从1开始找到大于等于target的边界r
        	r++;
        	sum += r;
        }
        while(r <= (target+1)/2)//r最多不会超过一半
        {
        	if(sum == target)
        	{	//相等
        		vector<int> t;
        		for(i = l; i <= r; ++i)
        			t.push_back(i);
        		if(t.size() > 1)
        			ans.push_back(t);
        		sum -= l;//更新左边界，让他少一个数
        		l++;
        	}
        	while(sum > target)
        	{	//大了，减少左边的数
        		sum -= l;
        		l++;
        	}
        	while(sum < target)
        	{	//小了，增加右边的数
        		r++;
        		sum += r;
        	}
        }
        return ans;
    }
};