#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int count[nums.size()+1];
        memset(count, 0, (nums.size()+1)*sizeof(int));
        int i, duplicated, missed;
        for(i = 0; i < nums.size(); ++i)
            count[nums[i]]++;
        for(i = 1; i <= nums.size(); ++i)
        {
            if(count[i] == 2)
                duplicated = i;
            if(count[i] == 0)
                missed = i;
        }
        return {duplicated, missed};
    }
};

int main()
{
    vector<int> v = {1,2,2,4};
    Solution s;
    s.findErrorNums(v);
    return 0;
}