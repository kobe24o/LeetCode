class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
    	int count[10] = {0}, i, n;
    	for(i = 0; i < digits.size(); ++i)
    		count[digits[i]]++;
    	string ans;
    	while(count[9]--)	ans += '9';
    	while(count[6]--)	ans += '6';
    	while(count[3]--)	ans += '3';
    	while(count[0]--)	ans += '0';
        for(i = 0; i < 10; ++i)
    	{
    		if(count[i] >= 3)
    		{
    			n = (count[i]/3-1)*3;
                count[i] -= n;
    			while(n--)
    				ans += char(i+'0');
    		}
    	}
    	while(count[8])
    	{
    		while(count[8] && count[7])
    		{
    			ans += "87";
    			count[8]--;
    			count[7]--;
    		}
    		while(count[8] && count[4])
    		{
    			ans += "84";
    			count[8]--;
    			count[4]--;
    		}
    		while(count[8] && count[1])
    		{
    			ans += "81";
    			count[8]--;
    			count[1]--;
    		}
            break;
    	}
    	while(count[7])
    	{
    		while(count[7] && count[5])
    		{
    			ans += "75";
    			count[7]--;
    			count[5]--;
    		}
    		while(count[7] && count[2])
    		{
    			ans += "72";
    			count[7]--;
    			count[2]--;
    		}
            break;
    	}
    	while(count[5])
    	{
    		while(count[5] && count[4])
    		{
    			ans += "54";
    			count[5]--;
    			count[4]--;
    		}
    		while(count[5] && count[1])
    		{
    			ans += "51";
    			count[5]--;
    			count[1]--;
    		}
            break;
    	}
    	while(count[4])
    	{
    		while(count[4] && count[2])
    		{
    			ans += "42";
    			count[4]--;
    			count[2]--;
    		}
            break;
    	}
    	while(count[2])
    	{
    		while(count[2] && count[1])
    		{
    			ans += "21";
    			count[2]--;
    			count[1]--;
    		}
            break;
    	}
    	
    	sort(ans.begin(), ans.end(),[](char& a, char& b){return a > b;});
    	if(ans != "" && ans[0]=='0')
    		return "0";
    	return ans;
    }
};