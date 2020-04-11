class Operations {
public:
    Operations() {

    }
    
    int minus(int a, int b) {
    	return a+(-b);
    }
    
    int multiply(int a, int b) {
    	if(a==0 || b==0)	return 0;
    	if(a==1)	return b;
    	if(b==1)	return a;
    	if(a== -1)	return -b;
    	if(b== -1)	return -a;
    	int negative = 0;
    	if(a < 0) negative += 1, a = -a;
    	if(b < 0) negative += 1, b = -b;
    	if(a > b) swap(a,b);
    	long temp = b;
    	vector<int> b_2, count;
    	int plus = 1;
    	while(temp <= INT_MAX)
    	{	
    		b_2.push_back(temp);
    		count.push_back(plus);//b乘以几得到上面的数temp
    		temp += temp;
    		plus += plus;
    	}
    	int ans = 0;
    	for(int i = b_2.size()-1; i >= 0; i=minus(i,1))
    	{
    		while(a >= count[i])
    		{
    			ans += b_2[i];
    			a = minus(a,count[i]);//把a拆分
    		}
    	}
    	if(negative==1)
    		return -ans;
    	return ans;
    }
    
    int divide(int a, int b) {
        if(a==0 || b==INT_MAX || b==INT_MIN) return 0;
        if(b==1) return a;
        if(b== -1) return -a;
        int negative = 0;
    	if(a < 0) negative += 1, a = -a;
    	if(b < 0) negative += 1, b = -b;
    	if(a < b) return 0;
    	long temp = b;
    	vector<int> b_2, count;
    	int plus = 1;
    	while(a >= temp)
    	{	
    		b_2.push_back(temp);
    		count.push_back(plus);//b乘以几得到上面的数temp
    		temp += temp;
    		plus += plus;
    	}
    	int ans = 0;
    	for(int i = b_2.size()-1; i >= 0; i=minus(i,1))
    	{
    		while(a >= b_2[i])
    		{
    			ans += count[i];//商+倍数
    			a = minus(a,b_2[i]);//把a减去b的倍数
    		}
    	}
    	if(negative==1)
    		return -ans;
    	return ans;
    }
};