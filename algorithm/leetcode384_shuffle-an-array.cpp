class Solution {
	vector<int> origin;
	vector<int> ans;
public:
    Solution(vector<int>& nums) {
        origin = ans = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = origin.size(),i;
        for(i = 0; i < n; ++i)
        	swap(ans[i], ans[rand()%n]);
        return ans;
    }
};