class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        int i, j, count = 0;
        for(i = 0; count < nums.size(); ++i)
        {
        	j = (i+k)%nums.size();
        	while(i != j)

        }
    }
};