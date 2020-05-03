class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
    	multimap<int,int> m;//value, idx
    	int i = 0, j, MAX, MIN, maxlen = 1;
    	for(j = 0; j < nums.size(); ++j)
    	{
    		m.insert(make_pair(nums[j],j));
    		MIN = m.begin()->first;
    		MAX = (--m.end())->first;
    		if(abs(nums[j]-MIN) <= limit && abs(nums[j]-MAX) <= limit)
    		{
    			maxlen = max(maxlen, int(m.size()));
    		}
			while(!(abs(nums[j]-MIN) <= limit && abs(nums[j]-MAX) <= limit))
			{
				auto it = m.lower_bound(nums[i++]);
				m.erase(it);
				MIN = m.begin()->first;
				MAX = (--m.end())->first;
			}
    	}
    	return maxlen;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> m;//value, count计数
        int i = 0, j = 0, MAX, MIN, maxlen = 1;
        while(j < nums.size())
        {
            m[nums[j]]++;//计数
            MIN = m.begin()->first;
            MAX = (--m.end())->first;
            if(abs(nums[j]-MIN) <= limit && abs(nums[j]-MAX) <= limit)
                maxlen = max(maxlen, j-i+1);
            else
            {
                while(!(abs(nums[j]-MIN) <= limit && abs(nums[j]-MAX) <= limit))
                {
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                        m.erase(nums[i]);
                    i++;
                    MIN = m.begin()->first;
                    MAX = (--m.end())->first;
                }
            }
            j++;
        }
        return maxlen;
    }
};