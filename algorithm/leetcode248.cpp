class Solution {
    vector<string> l = {"0","1","6","8","9"};
    vector<string> r = {"0","1","9","8","6"};
    int ans = 0;
public:
    int strobogrammaticInRange(string low, string high) {
        if(low.size() > high.size() || (low.size()==high.size() && low > high))
            return 0;
        vector<string> number = {"", "0","1","8"};
        for(int i = 0; i < number.size(); ++i)
        {
        	dfs(number[i], low, high);
        }
        return ans;
    }
    void dfs(string num, string& low, string& high)
    {
    	if(num.size() > high.size())
    		return;
    	if(num.size()>=low.size() && num.size() <= high.size())
        {
            if(num.size()==low.size() && num < low) 
                return;
            if(num.size()==high.size() && num > high)
                return;
            if(num.size() == 1 || num[0]!='0')
    		    ans++;
        }
    	for(int i = 0; i < 5; ++i)
    	{
    		dfs(l[i]+num+r[i], low, high);
    	}
    }
};