class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    	unordered_map<int, int> m;
    	for(auto n : nums)
    		m[n]++;
    	int sum = 0, num, count, target, add;
    	for(auto& num_count : m)
    	{
    		num = num_count.first;
    		count = num_count.second;
    		if(count == 0)
    			continue;
    		target = k-num;
            if(m.find(target) != m.end())
            {
                if(target != num)
    	            add = min(count, m[target]);
                else if(target == num)
                    add = count/2;
                sum += add;
                num_count.second -= add;
                m[target] -= add;
            }
    	}
    	return sum;
    }
};