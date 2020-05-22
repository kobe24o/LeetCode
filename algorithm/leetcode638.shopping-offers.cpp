class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    	int n = price.size();
    	int i,j,a,b,c,d,e,f, money;
    	for(i = 0; i < n; ++i)
    	{
    		vector<int> bag(7,0);
    		bag[i] = 1;
    		bag[6] = price[i];
    		special.push_back(bag);//单个物品，加入礼包
    	}
    	int dp[7][7][7][7][7][7];
        memset(dp,0x7f,sizeof(dp));//按字节赋值，1字节8位 0111 1111
    	dp[0][0][0][0][0][0] = 0;
    	vector<int> t(6,0);
        while(needs.size() < 6)
    		needs.push_back(0);
    	for(i = 0; i < needs.size(); ++i)
    		t[i] = needs[i];
    	for(vector<int> & s : special)
	    {
	    	vector<int> nd(6,0);
            money = s.back();
    		for(j = 0; j < s.size()-1; ++j)
    			nd[j] = s[j];
	    	for(a = 0; a <= t[0]; ++a)
	    		for(b = 0; b <= t[1]; ++b)
	    			for(c = 0; c <= t[2]; ++c)
	    				for(d = 0; d <= t[3]; ++d)
	    					for(e = 0; e <= t[4]; ++e)
	    						for(f = 0; f <= t[5]; ++f)
	    						{
	    							if(dp[a][b][c][d][e][f] != 0x7f7f7f7f && a+nd[0] <= needs[0]
	    								&& b+nd[1] <= needs[1] && c+nd[2] <= needs[2]
	    								&& d+nd[3] <= needs[3] && e+nd[4] <= needs[4]
	    								&& f+nd[5] <= needs[5])
	    								dp[a+nd[0]][b+nd[1]][c+nd[2]][d+nd[3]][e+nd[4]][f+nd[5]]
	    									= min(dp[a+nd[0]][b+nd[1]][c+nd[2]][d+nd[3]][e+nd[4]][f+nd[5]],
	    										dp[a][b][c][d][e][f]+money);
	    						}
		}
		return dp[t[0]][t[1]][t[2]][t[3]][t[4]][t[5]];
    }	
};