class Solution {
	vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(origin);
        int n = origin.size(),i;
        while(n--)
        {
        	if(n)
        		i = rand()%n;
        	else
        		i = 0;
        	ans.push_back(ans[i]);
        	ans.erase(ans.begin()+i);
        }
        return ans;
    }
};