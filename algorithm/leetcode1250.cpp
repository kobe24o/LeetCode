class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if(*s.begin()==1) return true;
        auto it = s.rbegin();
        int prev = *it, mod;
        for(it++; it != s.rend(); ++it)
        {
            if(*it == 0)
                break;
            mod = prev%*it;
            if(mod == 1)
                return true;
            else
                s.insert(mod);
            prev = *it;
        }
        return false;
    }
};