class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
    	vector<int> ans;
    	int i, num, bit;
    	bool flag;
        for(i = left; i <= right; ++i) 
        {
        	num = i;
        	flag = true;
        	while(num)
        	{
        		bit = num%10;
        		if(bit == 0 || i%bit != 0)
        			flag = false;
        		num /= 10;
        	}
        	if(flag)
        		ans.push_back(i);
        }
        return ans;
    }
};