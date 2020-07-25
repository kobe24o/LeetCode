class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
    	int odd = 0, even = 1, ans = 0, sum = 0, i;
    	for(i = 0; i < arr.size(); ++i)
    	{
    		sum += arr[i];
    		if(sum%2)//奇数
    		{
    			ans += even%1000000007;
    			odd++;
    		}
    		else if(sum%2==0)
    		{
    			ans += odd%1000000007;
    			even++;
    		}
    		ans %= 1000000007;

    	}
    	return ans;
    }
};