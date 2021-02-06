class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto n : nums)
            m[n]++;
        int ans = 0;
        for(auto mi : m)
            if(mi.second == 1)
                ans += mi.first;
        return ans;
    }
};
