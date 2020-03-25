class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
    	map<char,int> m;
    	vector<int> ans(2,0);
    	for(int i = 0; i < 4; ++i)
    	{
    		if(solution[i] == guess[i])//猜中了
                ans[0]++;
    		else//没猜中
                m[solution[i]]++;
    	}
    	for(int i = 0; i < 4; ++i)
    	{
            if(guess[i] != solution[i])//没猜中的里面，有伪猜中
            {
    		    if(m.count(guess[i]) && m[guess[i]] > 0)
    			    ans[1]++, m[guess[i]]--;
            }
    	}
    	return ans;
    }
};