class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
    	priority_queue<int,vector<int>,greater<int>> q;
    	for(auto& a : arr)
    		q.push(a);
    	arr.clear();
    	while(k--)
    	{
    		arr.push_back(q.top());
    		q.pop();
    	}
    	return arr;
    }
};