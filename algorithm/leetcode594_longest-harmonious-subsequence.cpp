class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        map<int,int> m;
        for(int num:nums)
        	m[num]++;
        int len = 0;
        auto it1 = m.begin(), it2 = ++m.begin();
        for( ; it2 != m.end(); ++it2)
        {
        	if(it1->first+1 == it2->first)
        		len = max(len, it1->second+it2->second);
        	it1 = it2;
        }
        return len;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        map<int,int> m;
        int len = 0;
        for(int num:nums)
        {
        	m[num]++;
        	//len = max(len,max(m[num]+m[num-1],m[num]+m[num+1]));//错误
        	//如果相邻的key不存在，答案就错了
        	if(m.count(num-1))
        		len = max(len, m[num]+m[num-1]);
        	if(m.count(num+1) != 0)
        		len = max(len, m[num]+m[num+1]);
        }
        return len;
    }
};