class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int i, j, sum = 0, benefit = 0, maxSum = 0;
        for(i = 0; i < customers.size(); ++i)
        	if(grumpy[i] == 0)//不生气，顾客满意
        		sum += customers[i];
        for(j = 0; j < X; ++j)
        	if(grumpy[j] == 1)//生气，控制住，带来的额外收益
        		benefit += customers[j];
        sum += benefit;
    	maxSum = sum;
    	for(i=0; j < customers.size(); ++i,++j)
    	{
    		if(grumpy[i] == 1)//左边滑出X窗口了，生气不再有收益
    			sum -= customers[i];
    		if(grumpy[j] == 1)//右边进入X窗口了，X控制我，我不生气
    			sum += customers[j];
    		maxSum = max(maxSum, sum); 
    	}
    	return maxSum;
    }
};