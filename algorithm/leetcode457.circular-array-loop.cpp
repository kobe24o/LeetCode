class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.empty()) return false;
        int i, j, count, nextidx, n = nums.size();
        for (i = 0; i < n; i++)
        {
        	j = i;//i 是起点
            count = 1;//个数计数
            vector<bool> visited(n,false);//是否访问过
            while(true)
            {
                if(visited[j])//重复访问，有环
                    break;
                visited[j] = true;
                nextidx = (nums[j]%n+j+n)%n;//下一个位置
                if(nums[j]*nums[nextidx] < 0)
                    break;//方向反了，不对，只能朝一个方向
                if(nextidx == i && count > 1)
                    return true;
                j = nextidx;
                count++;
            }
        }
        return false;
    }
};

class Solution {
	int next(vector<int>& nums, int i)
	{
		return (nums[i]%n+i+n)%n;//下一个位置
	}
    int n;
public:
    bool circularArrayLoop(vector<int>& nums) {
    	if(nums.empty()) return false;
    	int i, slow, fast, nt, count;
        n = nums.size();
    	for(i = 0; i < n; ++i)
    	{
    		if(nums[i] == 0)
    			continue;
    		slow = i;
    		fast = next(nums, i);//下一个位置
    		while(nums[slow]*nums[fast] > 0 && nums[fast]*nums[next(nums,fast)] > 0)
    		{
    			if(fast == slow)
    			{
    				if(slow == next(nums, slow))
    					break;//个数为1
    				else
    					return true;
    			}
    			slow = next(nums,slow);
    			fast = next(nums, next(nums,fast));
    		}
    		slow = i;
    		while(nums[slow]*nums[next(nums, slow)] > 0)
    		{	
    			nt = next(nums, slow);
    			nums[slow] = 0;//标记访问过了
    			slow = nt;
    		}
    	}
    	return false;
    }
};