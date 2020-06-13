class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    	int i = 0, j = 0, count = 0, product = 1;
    	for( ; j < nums.size(); ++j)
    	{
            if(i > j)
            {   //说明有数字 >= k
                j = i;//跳过该数字
                product = 1;//上一步product=0了
            }
    		while(j < nums.size() && product*nums[j] < k)
    		{   //右端点一直乘
    			product *= nums[j++];
                count += j-i;//以j-1结尾的子数组个数
    		}
    		if(j == nums.size())
    			return count;
    		while(i <= j && product*nums[j] >= k)
    		{   //乘积大了，左端点移走
    			product /= nums[i++];//有大于k的数的时候，product会变成0
    		}
            j--;//一会要++j,先减，还要再处理j
    	}
    	return count;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0, product = 1;
        while(j < nums.size())
        {
            if(product*nums[j] < k)
            {   //右端点一直乘
                product *= nums[j];
                count += j-i+1;//以j结尾的子数组个数
                j++;
            }
            else// (product*nums[j] >= k)
            {   //乘积大了，左端点移走
                product /= nums[i++];//有>=k的数的时候，product可能会变成0
                if(i > j)
                    j++, product=1;//跳过该数字
            }
        }
        return count;
    }
};