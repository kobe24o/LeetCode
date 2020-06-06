class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size(), idx = 0, i, j = 0;
        int time, amount;
    	vector<string> Na(n), Ct(n);
        vector<int> Ti(n), Amt(n);
    	string name, city;
    	for(string& tr : transactions)
    	{
    		name = city = "";
    		time = amount = j = 0;
    		for(i = 0; i < tr.size(); i++)
    		{
    			if(tr[i] == ',')
    			{
    				j++;
    				continue;
    			}
    			if(j == 0)
    				name += tr[i];
    			else if(j == 1)
    				time = time*10+tr[i]-'0';
    			else if(j == 2)
    				amount = amount*10+tr[i]-'0';
    			else
    				city += tr[i];
    		}
    		Na[idx] = name;
            Ct[idx] = city;
            Ti[idx] = time;
            Amt[idx++] = amount;
    	}
        vector<bool> valid(n, true);
        vector<string> ans;
    	for(i = 0; i < n; ++i)
        {
            if(Amt[i] > 1000)
                valid[i] = false;
            for(j = 0; j < i; ++j)
            {
                if(Na[i]==Na[j] && abs(Ti[i]-Ti[j]) <= 60 && Ct[i] != Ct[j])
                {
                    valid[i] = false;
                    valid[j] = false;
                }
            }
        }
        for(i = 0; i < n; ++i)
            if(!valid[i])
                ans.push_back(Na[i]+","+to_string(Ti[i])+","+to_string(Amt[i])+","+Ct[i]);
        return ans;
    }
};