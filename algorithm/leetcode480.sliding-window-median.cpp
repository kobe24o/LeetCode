class Solution {	// C++
    multiset<int> minheap;//begin 是小的元素
    multiset<int,greater<int>> maxheap;//begin 是大的元素
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    	// k = 1，直接返回数组
        if(k == 1) return vector<double>(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = 0, idx = 0;
        long a, b;//避免溢出 long
        vector<double> ans(n-k+1);
        for( ; j < k; ++j)
            maxheap_minheap_add(nums[j]);//先加入k个
        a = (*maxheap.begin()), b = (*minheap.begin());
        ans[idx++] = (k&1) ? b : (a+b)/2.0;//记录中位数
        for(i = 0 ; j < n; ++i,++j)
        {
            maxheap_minheap_del(nums[i]);//删除左端点
            maxheap_minheap_add(nums[j]);//加入右端点
            a = (*maxheap.begin()), b = (*minheap.begin());
            ans[idx++] = (k&1) ? b : (a+b)/2.0;//记录中位数
        }
        return ans;
    }

    void maxheap_minheap_add(int x)
    {
        if(minheap.empty())
            minheap.insert(x);
        else if(maxheap.size() == minheap.size())
        {
            if(x >= *maxheap.begin())
                minheap.insert(x);
            else
            {
                minheap.insert(*maxheap.begin());
                maxheap.erase(maxheap.begin());
                maxheap.insert(x);
            }
        }
        else if(maxheap.size() < minheap.size())
        {
            if(x <= *maxheap.begin())
                maxheap.insert(x);
            else
            {
                maxheap.insert(*minheap.begin());
                minheap.erase(minheap.begin());
                minheap.insert(x);
            }
        }
    }
    void maxheap_minheap_del(int x)
    {
        if(maxheap.size() < minheap.size())
        {
            auto it = minheap.find(x);
            if(it != minheap.end())
                minheap.erase(it);
            else
            {
                maxheap.erase(maxheap.find(x));
                maxheap.insert(*minheap.begin());
                minheap.erase(minheap.begin());
            }
        }
        else if(maxheap.size() == minheap.size())
        {
            auto it = maxheap.find(x);
            if(it != maxheap.end())
                maxheap.erase(it);
            else
            {
                minheap.erase(minheap.find(x));
                minheap.insert(*maxheap.begin());
                maxheap.erase(maxheap.begin());
            }
        }
    }
};