class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cA = 0, cB = 0;
        int numA, numB, i;
        for(i = 0; i < n; i++) 
        {
        	if(cA == 0 || cB == 0)
        	{
        		if(cA == 0 && cB == 0)
        		{
        			numA = nums[i];
        			cA++;
        		}
        		else if(cA != 0 && cB == 0)
        		{
        			if(numA == nums[i])
        				cA++;
        			else
        			{
        				numB = nums[i];
        				cB++;
        			}
        		}
        		else	//cA == 0 && cB != 0
        		{
        			if(numB == nums[i])
        				cB++;
        			else
        			{
        				numA = nums[i];
        				cA++;
        			}
        		}
        	}
        	else	// 都不为零
        	{
        		if(nums[i] == numA)
        			cA++;
        		else if(nums[i] == numB)
        			cB++;
        		else
        		{
                    cB--;
                    cA--;
        		}
        	}
        }
        if(cA == 0 && cB == 0)
        	return {};
        int nA=0, nB=0;
        for(i = 0; i < n; i++)
        {
        	if(nums[i] == numA)
        		nA++;
        	else if(nums[i] == numB)
        		nB++;
        }
        vector<int> ans;
        if(nA >= n/3+1)
        	ans.push_back(numA);
        if(nB >= n/3+1)
        	ans.push_back(numB);
        return ans;
    }
};s