class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, j, count, k = 0;
        vector<int> ans(nums.size());
        for(i = 0; i < nums.size(); ++i)
        {
            count = 0;
            for(j = 0; j < nums.size(); ++j)
            {
                if(nums[j] < nums[i])
                    count++;
            }
            ans[k++] = count;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    	unordered_map<int,int> idx;
    	vector<int> ans(nums.size());
    	vector<int> sortNums(nums);
    	sort(sortNums.begin(), sortNums.end());
    	for(int i = nums.size()-1; i >= 0; --i)
    		idx[sortNums[i]] = i;
    	for(int i = 0, j = 0; i < nums.size(); ++i, ++j)
    		ans[j] = idx[nums[i]];
    	return ans;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    	vector<int> ans(nums.size());
    	int count[101] = {0}, sum = 0, lesscur = 0;
    	for(int i = 0; i < nums.size(); ++i)
    		count[nums[i]]++;
    	for(int i = 0; i < 101; ++i)
    	{
    		sum += count[i];
    		count[i] = lesscur;
    		lesscur = sum;
    	}
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		ans[i] = count[nums[i]];
    	}
    	return ans;
    }
};