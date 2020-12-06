class Solution {
    int mindiff = INT_MAX;
    int size;//每个集合的大小
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        if(k == nums.size())//特殊情况
            return 0;
        unordered_map<int, int> m;
        sort(nums.begin(), nums.end());
        for(auto n : nums)
        {
            if(++m[n] > k)
                return -1;
        }
        size = nums.size()/k;
        vector<int> curnum(k), count(k, 0);//每个集合当前的数，集合大小
        dfs(nums, curnum, count, 0, 0);
        return mindiff;
    }   
    void dfs(vector<int>& nums, vector<int>& curnum, vector<int>& count, int i, int diff)
    {
        if(diff >= mindiff)//剪枝
            return;
        if(i == nums.size())
        {
            if(diff < mindiff)
                mindiff = diff;
            return;
        }
        for(int j = 0; j < count.size(); ++j)
        {
            if(curnum[j] == nums[i])//存在相同的数字了
                continue;
            if(count[j] < size)//集合还没满
            {
                int originnum = curnum[j];//集合当前的数字
                curnum[j] = nums[i];//nums[i] 放入集合 j
                count[j]++;//集合大小 + 1
                int delta = count[j] >= 2 ? (nums[i]-originnum) : 0;// diff 增量
                dfs(nums, curnum, count, i+1, diff+delta);
                count[j]--;
                curnum[j] = originnum;
                if(count[j] == 0)//都是空的集合，这个数字放在哪个集合都是一样的，不写这句，会超时
                    break;
            }
        }
    }
};// 28 ms  7.6 MB  C++