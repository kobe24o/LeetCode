class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen = 0;
        vector<vector<int>> lr;//记录所有区间
        int l = -1, r = -1;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(nums[i]&&l==-1)
                l = i;
            if(l != -1 && nums[i]==0 && r==-1)
                r = i-1;
            if(nums[i] && i == nums.size()-1)
                r = nums.size()-1;
            if(l!=-1 && r!=-1)
            {
                lr.push_back({l,r});
                l = r = -1;
            }
        }
        if(lr.size()==0)
            return 0;
        if(lr.size()==1)
        {
            if(lr[0][0]!=0 || lr[0][1]!=nums.size()-1)
                return lr[0][1]-lr[0][0]+1;
            else
                return nums.size()-1;
        }
        maxlen = max(maxlen, lr[0][1]-lr[0][0]+1);
        for(int i = 0,j; i < lr.size()-1; i++)
        {
            j = i+1;//判断相邻的两个区间能否合并
            if(lr[i][1]+2==lr[j][0])
                maxlen = max(maxlen, lr[j][1]-lr[i][0]);
            else
                maxlen = max(maxlen, lr[j][1]-lr[j][0]+1);
        }
        return maxlen;
    }
};