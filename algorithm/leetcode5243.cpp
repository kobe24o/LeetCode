class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
                m[nums[i]*nums[j]]++;
        }
        int ans = 0;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            int n = it->second;
            ans += n*(n-1)*4;
        }
        return ans;
    }
};