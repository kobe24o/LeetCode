class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int i, j, left, right;
        vector<int> ans(S.size());
        vector<int> positionsC;
        for(i = 0; i < S.size(); ++i) 
        {
        	if(S[i] == C)
        		positionsC.push_back(i);
        }
        positionsC.insert(positionsC.begin(),-20000);
        positionsC.push_back(300000);
        left = positionsC[0];
        right = positionsC[1];
        for(i = 0, j = 1; i < S.size(); ++i) 
        {
        	if(S[i] == C)
    		{
    			ans[i] = 0;
    			left = right;
    			right = positionsC[++j];
    		}
        	else
        	{
        		ans[i] = min(i-left,right-i);
        	}
        }
        return ans;
    }
};