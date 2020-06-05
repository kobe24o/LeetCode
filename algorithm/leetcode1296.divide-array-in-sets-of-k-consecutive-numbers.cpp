class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0)
            return false;
        map<int,int> m;
        for(int i = 0; i < nums.size(); ++i)
            m[nums[i]]++;
        int cur, prev, i, count;
        while(!m.empty())
        {
            i = count = prev = 0;
            for(auto it = m.begin(); it != m.end() && i < k; ++it,++i)
            {
                if(prev == 0)
                {
                    count = it->second;//第一个数的计数
                    prev = it->first;
                    m.erase(it);
                }
                else
                {
                    if(prev+1 != it->first || it->second < count)
                        return false;//数不连续，或者个数不够
                    m[prev+1] -= count;
                    if(m[prev+1] == 0)
                        m.erase(prev+1);
                    prev++;
                }
            }
            if(i != k)
                return false;//个数不够
        }
        return true;
    }
};