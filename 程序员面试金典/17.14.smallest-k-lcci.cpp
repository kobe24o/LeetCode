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

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
    	sort(arr.begin(),arr.end());
        return vector<int>(arr.begin(),arr.begin()+k);
    }
};

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty()||(k==0))
            return {};
    	findkth(arr,k,0,arr.size()-1);
    	return vector<int> (arr.begin(), arr.begin()+k);
    }

    int findkth(vector<int>& arr, int& k, int l, int r)
    {
    	selectMid(arr,l,r);
    	int p = arr[l];
    	int i = l, j = r;
    	while(i < j)
    	{
    		while(i < j && arr[j] > p)
    			j--;
    		swap(arr[i],arr[j]);
    		while(i < j && arr[i] <= p)
    			i++;
    		swap(arr[i],arr[j]);
    	}
    	if(i == k)
    		return i;
    	else if(i < k)
    		return findkth(arr,k,i+1,r);
    	return findkth(arr,k,l,i-1);
    }

    void selectMid(vector<int>& arr, int& l, int& r)
    {
    	int mid = l+((r-l)>>1);
    	if(arr[mid] > arr[r])
    		swap(arr[mid],arr[r]);
    	if(arr[l] > arr[r])
    		swap(arr[mid],arr[r]);
    	if(arr[mid] > arr[l])
    		swap(arr[mid],arr[l]);
    }
};