class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto n : nums)
            m[n]++;
        vector<pair<int,int>> arr;
        for(auto p : m)
        {
            arr.push_back(p);
        }
        sort(arr.begin(), arr.end(),[&](auto a, auto b) {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });
        vector<int> ans(nums.size());
        int i = 0, t, number;
        for(auto p : arr)
        {
            t = p.second;
            number = p.first;
            while(t--)
                ans[i++] = number;
        }
        return ans;
    }
};