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

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        ans[0] = 0;
        for(int i = 0; i <= num; ++i)
        {
            if(i % 2 == 1)
            {
                ans[i] = ans[i-1] + 1;
            }
            else
            {
                ans[i] = ans[i/2];
            }
        }
        return ans;
    }
};