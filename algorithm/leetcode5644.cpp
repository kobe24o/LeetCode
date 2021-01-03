class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
    	unordered_map<int,int> num_idx;
    	for(int i = 0; i < target.size(); ++i)
    		num_idx[target[i]] = i;
    	vector<int> arr_idx;
    	for(auto a : arr)
    		if(num_idx.find(a) != num_idx.end())
    			arr_idx.push_back(num_idx[a]);//存的idx
    			//转化成在 arr_idx 中找最长上升子序列
    	// 数据量很大，不能用 n^2 解法，需要 nlgn 解法
    	vector<int> dp;//存最长上升子序末尾最小的数
    	dp.reserve(num_idx.size()+1);//容量，避免搬移
    	for(int i = 0; i < arr_idx.size(); ++i)
    	{
    		int cur = arr_idx[i];
    		auto pos = lower_bound(dp.begin(),dp.end(),cur);
    		if(pos == dp.end())
    			dp.push_back(cur);
    		else
    			*pos = cur;
    	}
    	return target.size()-dp.size();
    }
};