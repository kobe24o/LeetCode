class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        unordered_map<int,int> m;
        for(int num:nums)
        	m[num]++;
        int sum = 0;
        if(k != 0)
        {
            for(auto p : m)
                if(m.count(p.first+k))
                    sum++;
        }
        else
            for(auto it = m.begin(); it != m.end(); ++it)
                if(it->second >= 2)
                    sum++;
    	return sum;
    }
};