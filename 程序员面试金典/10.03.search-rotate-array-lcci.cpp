class Solution {
public:
    int search(vector<int>& arr, int target) {
    	int l = 0, r = arr.size()-1, mid;
    	while(l < r)
    	{
    		mid = l+((r-l)>>1);
    		if(arr[l] == arr[mid])
    		{
    			if(arr[l] == target)
    				r = l;
    			else
    				l++;
    		}
    		else if(arr[l] > arr[mid])
    		{
    			if(arr[l] <= target || target <= arr[mid])
    				r = mid;
    			else
    				l = mid+1;
    		}
    		else if(arr[l] < arr[mid])
    		{
    			if(arr[l] <= target && target <= arr[mid])
    				r = mid;
    			else
    				l = mid+1;
    		}
    	}
    	return arr[l]==target ? l : -1;
    }
};