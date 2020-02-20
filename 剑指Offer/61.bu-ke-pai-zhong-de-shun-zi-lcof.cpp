class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());//排序
        int zero = 0, i = 0, prev;
        while(i < nums.size() && nums[i] == 0)
        	zero++, i++;//找大小王，计数
        if(i < nums.size())
        	prev = nums[i++];//第一个非王的牌
        for( ;i < nums.size(); ++i)
        {
        	if(nums[i]==prev+1)
        		prev = nums[i];
        	else if(zero)//不相差1，且还有王
        	{
        		zero--;//王补上
        		prev = prev+1;//前一个数+1
        		i--;//继续对这张牌进行判断
        	}
        	else//不相差1，没王了
        		return false;
        }
        return true;
    }
};