class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
    	vector<int> temp(arr);
    	int i, n = arr.size();
    	while(1)
    	{
    		for(i = 1; i < n-1; ++i)
    		{
    			if(arr[i-1] > arr[i] && arr[i] < arr[i+1])
    				temp[i]++;
    			else if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
    				temp[i]--;
    		}
    		if(temp == arr)
    			break;
    		arr = temp;
    	}
    	return arr;
    }
};