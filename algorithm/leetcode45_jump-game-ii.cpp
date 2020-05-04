class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, i, reach = 0, maxs = 0;
        for(i = 0; i < nums.size()-1; ++i)
        {
        	maxs = max(maxs,nums[i]+i);
        	if(i == reach)
        	{
        		++steps;
        		reach = maxs;
        	}
        }
        return steps;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        queue<int> q;//idx
        int i, size, step = 0, tp, maxIdx = 0, nextIdx, n = nums.size();
        q.push(0);
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                tp = q.front();
                if(tp >= n-1)
                    return step;
                nextIdx = min(n-1,max(maxIdx, tp+nums[tp]));
                q.pop();
                for(i = maxIdx+1; i <= nextIdx; ++i)
                    q.push(i);
                maxIdx = nextIdx;
            }
            step++;
        }
        return step;
    }
};