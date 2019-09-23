#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i, j, one = 0;
        string ans;
        for(i = a.size()-1,j = b.size()-1; i >= 0 && j >= 0; --i,--j)
        {
        	if((a[i]-'0')^(b[j]-'0'))
        	{
        		if(one == 0)
        			ans = "1"+ans;
        		else
        		{
        			ans = "0"+ans;
        			// one = 1;
        		}
        	}
        	else
        	{
        		if(a[i]== '0' && b[j]== '0')
        		{
        			if(one == 0)
        				ans = "0"+ans;
        			else
        			{
        				ans = "1"+ans;
        				one = 0;
        			}
        		}
        		else//都为1
        		{
        			if(one == 0)
        			{
        				ans = "0"+ans;
        				one = 1;
        			}
        			else
        			{
        				ans = "1"+ans;
        			}
        		}	
        	}
        }
        if(j < 0 && i >= 0)
        {
        	while(i >= 0)
        	{
        		if((a[i]-'0')^one)
        		{
        			ans = "1"+ans;
        			one = 0;
        		}
        		else
        		{
        			if(a[i]== '0' && one == 0)
        			{
        				ans = "0"+ans;
        			}
        			else
        			{
        				ans = "0"+ans;
        				one = 1;
        			}
        		}
        		i--;
        	}
        	if(one)
        		ans = "1"+ans;
        }
        else // (i < 0)
        {
        	while(j >= 0)
        	{
        		if((b[j]-'0')^one)
        		{
        			ans = "1"+ans;
        			one = 0;
        		}
        		else
        		{
        			if(b[j]== '0' && one == 0)
        			{
        				ans = "0"+ans;
        			}
        			else
        			{
        				ans = "0"+ans;
        				one = 1;
        			}
        		}
        		j--;
        	}
        	if(one)
        		ans = "1"+ans;
        }
        return ans;
    }
};
int main()
{
	Solution s;
	s.addBinary("11","1");
}

