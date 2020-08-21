class Solution {
	
public:
    int minBudget(vector<int>& people, vector<int>& budget, int num) {
    	int l = 1, r = 1e7, mid, ans, n = people.size();
    	vector<pair<double, int>> avg(n);
    	for(int i = 0; i < n; i++) 
    	{
    		avg[i] = {budget[i]/double(people[i]), i};
    	}
    	sort(avg.begin(), avg.end(), [&](auto a, auto b){
            if(fabs(a.first-b.first) < 1e-6)
                return people[a.second] < people[b.second];
            return a.first > b.first;
        });
        int sum = 0, count = 0, i = 0, idx;
        while(i < num)
        {
            idx = avg[i++].second;
            sum += budget[idx];
            count += people[idx];
        }
        int target = ceil(sum/double(count));
    	while(l < r)
    	{
    		mid = l+((r-l)>>1);
    		if(mid >= target)
    		{
    			ans = mid;
    			r = mid-1;
    		}
    		else
    			l = mid+1;
    	}
    	return ans;
    }
};