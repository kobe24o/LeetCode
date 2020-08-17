class Solution {
public:
    bool isPossible(vector<int>& nums) {
    	unordered_map<int,int> tail, cnt;
    	for(int n : nums)
    		cnt[n]++;//计数
    	for(int n : nums)
    	{
    		if(cnt[n]==0)
    			continue;
    		if(tail[n-1] > 0)//有以n-1结尾的，接上
    		{
    			tail[n-1]--;
    			tail[n]++;
    			cnt[n]--;
    		}
    		else if(cnt[n+1]>0 && cnt[n+2]>0)
    		{	//后面有两个可以跟我连接，接上
    			cnt[n]--;
    			cnt[n+1]--;
    			cnt[n+2]--;
    			tail[n+2]++;
    		}
    		else
    			return false;
    	}
    	return true;
    }
};