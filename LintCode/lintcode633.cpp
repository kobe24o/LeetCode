class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int i = 0;
        while(nums[i] != nums[nums[i]])
            myswap(nums[i], nums[nums[i]]);
        return nums[i];
    }
    
    inline void myswap(int& a, int& b)
    {
        a ^= b ^= a ^= b;
    }
};

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int fast = 0;
        int slow = 0;
        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        while(fast != slow);
        
        slow = 0;
        while (slow != fast) 
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int idx, i;
        for(i = 0; i < nums.size(); ++i)
        {
            idx = abs(nums[i]);
            if(nums[idx] > 0)
                nums[idx] = -nums[idx];
            else
                return idx;
        }
        return -1;
    }
};