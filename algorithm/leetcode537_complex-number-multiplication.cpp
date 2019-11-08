class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int x1, y1, x2, y2, x, y;
        getxy(a,x1,y1);
        getxy(b,x2,y2);
        x = x1*x2-y1*y2;
        y = x1*y2+x2*y1;
        string ans(to_string(x)+"+"+to_string(y)+"i");
        // ans.append(to_string(x)+"+"+to_string(y)+"i");
        return ans;
    }

    void getxy(string &s, int &x, int &y)
    {
    	int sum = 0;
    	bool negative = false;
    	for(int i = 0; i < s.size(); ++i)
    	{
    		if(isdigit(s[i]))
    			sum = sum*10+s[i]-'0';
    		else
    		{
    			if(s[i] == '-')
    				negative = true;
    			else if(s[i] == '+')
    			{
    				x = negative == true ? -sum : sum;
    				negative = false;
    				sum = 0;
    			}
    			else// s[i] == 'i'
    			{
    				y = negative == true ? -sum : sum;
    			}
    		}

    	}
    }
};