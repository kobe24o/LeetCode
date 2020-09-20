class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long mod = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            mod = (mod + nums[i])%p;
            sum += nums[i];
        }
        if(mod == 0)//余数为0，不需要操作
            return 0;
        if(sum < p)//和小于p, 做不到
            return -1;
        int s = 0, minlen = INT_MAX;
        // s 是求模后的和
        unordered_map<int, int> m;//记录和求模后的数，及其位置
        m[0] = -1;//初始条件，0 在 -1 位置
        for(int i = 0; i < nums.size(); i++)
        {
            s = (s + nums[i])%p;
            int target = (s-mod+p)%p;
            //检查跟 s 相差 需要的余数mod 的余数存在吗
            if(m.find(target) != m.end())
            {
                minlen = min(minlen, i-m[target]);
            }
            m[s] = i;//更新位置
        }
        return minlen >= nums.size() ? -1 : minlen;
    }
};