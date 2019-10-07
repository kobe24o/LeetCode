#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k == 0)
        	return;
        int i, j, j0, count = 0, prev, next = nums[0];
        for(i = 0; count < nums.size(); ++i)
        {
        	j0 = i;
        	prev = nums[j0];
        	while(i != j)
        	{
	        	j = (j0+k)%nums.size();
        		next = nums[j];
        		nums[j] = prev;
        		j0 = j;
        		prev = next;
        		++count;
        	}	
        }
    }
};
int main()
{
	Solution s;
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	s.rotate(nums,3);
}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k == 0)
        	return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};