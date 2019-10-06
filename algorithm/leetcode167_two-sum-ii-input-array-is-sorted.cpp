class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1, sum;
        sum = numbers[i]+numbers[j];
        while(i < j)
        {
            sum = numbers[i]+numbers[j];
            if(sum == target)
                return {i+1,j+1};
            else if(sum < target)
                i++;
            else
                --j;
        }
        return {};
    }
};