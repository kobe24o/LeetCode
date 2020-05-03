class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool flag = true;
        int i, count = 0, prev = -1;
        vector<int> pos;
        for(i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 1)
                pos.push_back(i);
        }
        for(i = 0; i < int(pos.size())-1; ++i)
        {
            if(pos[i+1]-pos[i] <= k)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i, prevOneIdx = -1000000;
        for(i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 1)
            {
                if(i-prevOneIdx <= k)
                    return false;
                prevOneIdx = i;
            }
        }
        return true;
    }
};