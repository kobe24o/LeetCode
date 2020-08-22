class Solution {
	bool can = false;
public:
    bool judgePoint24(vector<int>& nums) {
    	vector<double> number(4);
        for(int i = 0; i < 4; ++i)
            number[i] = double(nums[i]);
    	check(number);
    	return can;
    }
    void check(vector<double>& nums) 
    {
    	if(can) return;
    	if(nums.size() == 1)
    	{
    		if(fabs(nums[0]-24) < 1e-6)
    			can = true;
    		return;
    	}
    	for(int i = 0; i < nums.size(); i++)
    	{
    		for(int j = 0; j < nums.size(); j++)
    		{
    			if(i == j)
    				continue;
    			vector<double> temp;
    			for(int k = 0; k < nums.size(); k++)
    				if(k != i && k != j)
    					temp.push_back(nums[k]);
    			for(int k = 0; k < 4; k++)
    			{
    				if(k < 2 && i > j)
    					continue;// + * 法满足交换律
    				if(k == 0)
    					temp.push_back(nums[i]+nums[j]);
    				else if(k == 1)
    					temp.push_back(nums[i]*nums[j]);
    				else if(k == 2)
    					temp.push_back(nums[i]-nums[j]);
    				else
    					temp.push_back(nums[i]/nums[j]);
    				check(temp);
    				temp.pop_back();
    			}
    		}
    	}
    }
};