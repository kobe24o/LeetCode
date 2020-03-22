class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        pair<bool,int> p;
        for(int i = 0; i < nums.size(); ++i)
        {
        	p = isfour(nums[i]);
            if(p.first)
                sum += p.second;
        }
        return sum;
    }

    pair<bool, int> isfour(int &n)
    {
    	if(n == 1)
    		return {false, 0};
    	int count = 2;
    	int divs = 1+n;
    	for(int i = 2; i <= n/2; ++i)
    	{
    		if(n%i == 0)
    		{
    			count++;
    			divs += i;
            }
    		if(count > 4)
    			return {false,0};
    	}
    	return {count==4,divs};
    }
};

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        pair<bool,int> p;
        for(int i = 0; i < nums.size(); ++i)
        {
        	p = isfour(nums[i]);
            if(p.first)
                sum += p.second;
        }
        return sum;
    }

    pair<bool, int> isfour(int &n)
    {
    	if(n == 1)
    		return {false, 0};
    	int count = 2;
    	int divs = 1+n;
    	for(int i = 2; i <= sqrt(n); ++i)
    	{
    		if(n%i == 0)
    		{
                if(i != n/i)
    			{
                    count += 2;
    			    divs += i+n/i;
                }
                else
                {
                    count += 1;
                    divs += i;
                }
            }
    		if(count > 4)
    			return {false,0};
    	}
    	return {count==4,divs};
    }
};