class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
    	int l = 0, r = 1e9, mid, ans;
        K++;//包含自己
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		if(!cansplitK(sweetness, mid,K))
    			r = mid-1;
    		else
    			ans = mid, l = mid+1;
    	}
    	return ans;
    }
    bool cansplitK(vector<int>& sweet, int s, int K)
    {
    	int people = 0, total = 0;
    	for(int i = 0; i < sweet.size(); ++i)
    	{
    		total += sweet[i];
    		if(total >= s)
    		{
    			people++;
    			total = 0;
    			if(people >= K)
    				return true;
    		}
    	}
    	return people >= K;
    }
};