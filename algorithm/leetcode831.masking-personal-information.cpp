class Solution {
public:
    string maskPII(string S) {
    	int at = S.find("@");
    	string ans;
    	if(at != string::npos)
    	{
    		if(isupper(S[0]))
    			ans = string(1,S[0]+32)+"*****";
    		else
    			ans = string(1,S[0])+"*****";
    		for(int i = at-1; i < S.size(); ++i)
    		{
    			if(isupper(S[i]))
    				S[i] += 32;
    			ans += S[i];
    		}
    	}
        else
        {
            int count = 0;
            string last4;
            for(int i = S.size()-1; i >= 0; --i)
            {
                if(isdigit(S[i]))
                {
                    count++;
                    if(last4.size()<4)
                        last4 = S[i]+last4;
                }
            }
            if(count<=10)
                ans = "***-***-"+last4;
            else
                ans = "+"+string(count-10,'*')+"-***-***-"+last4;
        }
    	return ans;
    }
};