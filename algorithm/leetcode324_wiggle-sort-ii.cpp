#include<vector>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        int n = (nums.size()+1)/2, len = nums.size();
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin()+n);
        reverse(temp.begin()+n, temp.end());
        int i = 0, j = n, k = 0;
        while(k < len)
        {
        	nums[k++] = temp[i++];
        	if(k < len)
        		nums[k++] = temp[j++];
        }
    }
};
int main()
{
	Solution s;
	s.wiggleSort({1, 5, 1, 1, 6, 4;});
}