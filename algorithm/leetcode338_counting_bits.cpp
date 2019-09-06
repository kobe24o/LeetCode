class Solution {
public:
    vector<int> countBits(int num) {
        int count, temp;
        vector<int> ans;
        for(int i = 0; i <= num; ++i)
        {
            count = 0;
            temp = i;
            while(temp)
            {
                temp &= (temp-1);
                ++count;
            }
            ans.push_back(count);
        }
        return ans;
    }
};