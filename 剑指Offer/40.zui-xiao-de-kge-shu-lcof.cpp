class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        return vector<int> (arr.begin(), arr.begin()+k);
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> q;//默认最大堆
       	for(auto& a : arr)
       	{
       		if(q.size() < k)
       			q.push(a);
       		else
       		{
       			if(!q.empty() && a < q.top())
       			{
       				q.pop();
       				q.push(a);
       			}
       		}
       	}

       	vector<int> ans;
       	while(!q.empty())
       	{
       		ans.push_back(q.top());
       		q.pop();
       	}
       	return ans;
    }
};