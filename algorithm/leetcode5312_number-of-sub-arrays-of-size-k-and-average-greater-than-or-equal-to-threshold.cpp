class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = k-1, n = arr.size(), sum=0, target = k*threshold;
        int count = 0;
        for(i = 0; i < k; i++) 
        	sum += arr[i];
        if(sum >= target)
        	count++;
        i=1,j++;
        while(j < n)
        {
        	sum += arr[j]-arr[i-1];
        	if(sum >= target)
        		count++;
            i++,j++;
        }
        return count;
    }
};