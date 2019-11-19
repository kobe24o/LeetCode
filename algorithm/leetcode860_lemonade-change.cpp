class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m5 = 0, m10 = 0;//mx是x元钱的张数
        for(int bill : bills)
        {
        	if(bill == 5)
        		m5++;
        	else if(bill == 10)
        	{
        		m10++;
        		if(m5 <= 0)
        			return false;
        		m5--;//找5元
        	}
        	else//bill == 20,找15元
        	{
        		if(m10 > 0)
        		{
        			m10--;//优先找10元
        			if(m5 <= 0)
        				return false;
        			m5--;
        		}
        		else//没有10元的，找3张5元
        		{
        			if(m5 < 3)
        				return false;
        			m5 -= 3;
        		}
        	}
        }
        return true;
    }
};