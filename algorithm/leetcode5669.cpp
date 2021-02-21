class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, j = 0, n1 = groups.size(), n2 = nums.size();
        while(i < n1 && j < n2)
        {
            int k = 0, len = groups[i].size();
            int J = j;
            while(k < len && j < n2)
            {
                if(groups[i][k] == nums[j])
                    k++, j++;
                else
                    break;
            }
            if(k != len)
                j = J+1;
            else
                i++;
        }
        return i == n1;
    }
};