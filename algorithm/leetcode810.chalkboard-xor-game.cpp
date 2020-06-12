class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if(nums.size()%2==0)
            return true;
        int XOR = 0;
        for(int i = 0; i < nums.size(); ++i)
            XOR ^= nums[i];
        return XOR==0;
    }
};