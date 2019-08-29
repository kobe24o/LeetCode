class Solution {//bitmap solution
public:
    int findDuplicate(vector<int>& nums) {
        int idx, bit;
        int numOfBytes = (nums.size()-1)/8+1;
        char bytes[numOfBytes];
        memset(bytes,0,numOfBytes*sizeof(char));
        for(int i = 0; i < nums.size(); ++i)
        {
            idx = nums[i]/8, bit = nums[i]%8;
            if(!(bytes[idx]&(1<<bit)))
                bytes[idx] |= (1<<bit);
            else
                return nums[i];
        }
        return -1;
    }
};

class Solution {//set solution
public:
    int findDuplicate(vector<int>& nums) {
    	set<int> s;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(s.find(nums[i]) == s.end())
                s.insert(nums[i]);
            else
                return nums[i];
        }
        return -1;
    }
};

class Solution {//O(1)复杂度
public:
    int findDuplicate(vector<int>& nums) {
    	int fast = nums[0], slow = nums[0];
        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        while(fast != slow);
        fast = nums[0];
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};