class Solution {
public:
    int ratJump(vector<int> &arr) {
        int i, n = arr.size();
        long odd[n+3] = {0};
        long even[n+3] = {0};
        reverse(arr.begin(),arr.end());
        arr.push_back(0);
        arr.push_back(0);
        arr.push_back(0);
        if(arr[0]==0)
        	odd[0] = 1;
        if(arr[1]==0)
        {
        	odd[1] = 1;
        	if(arr[0]==0)
        		even[1] = 1;
        }
        for(i = 2; i < n+3; ++i)
        {
        	odd[i] = (i-1>=0 && i-1 < n-1 && arr[i-1]==0 && even[i-1]) ? even[i-1] : 0 
        			+ (i-2>=0 && i-2 < n-1 && arr[i-2]==0 && even[i-2]) ? even[i-2] : 0
        			+ (i-4>=0 && i-4 < n-1 && arr[i-4]==0 && even[i-4]) ? even[i-4] : 0;
			odd[i] %= 1000000007;
			even[i] = (i-1>=0 && i-1 < n-1 && arr[i-1]==0 && odd[i-1]) ? odd[i-1] : 0 
        			+ (i-3>=0 && i-3 < n-1 && arr[i-3]==0 && odd[i-3]) ? odd[i-3] : 0
        			+ (i-4>=0 && i-4 < n-1 && arr[i-4]==0 && odd[i-4]) ? odd[i-4] : 0;
			even[i] %= 1000000007;
        }
        long sum = 0;
        for(i = n-1; i < n+3; ++i)
        {
        	sum += odd[i]+even[i];
        	sum %= 1000000007;
        }
        return sum;
    }
};