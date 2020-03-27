class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size()+2, a, b;
        long sum = 0, squareSum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            squareSum += nums[i]*nums[i];
        }
        squareSum = long(n)*(n+1)*(2*n+1)/6 - squareSum;
        sum = n*(n+1)/2 - sum;
        for(a = 1; a <= n; ++a)
        {
            if(2*a*(sum-a) == sum*sum - squareSum)
                break;
        }
        b = sum-a;
        return {a,b};
    }
};

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i, j;
        for(i = 1, j = 0; i <= nums.size()+2 && j < nums.size(); ++i)
        {
            if(nums[j] != i)
                ans.push_back(i);
            else
                j++;
            if(ans.size()==2)
                return ans;
        }
        if(ans.size()==1)
            ans.push_back(i);
        else if(ans.size()==0)
        {
            ans.push_back(i);
            ans.push_back(i+1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int XOR = 0, a = 0, b = 0, i;
        for(auto& n : nums) XOR ^= n;
        for(i = 1; i <= nums.size()+2; ++i) XOR ^= i;
        for(i = 0; i < 32; ++i)
            if(XOR&(1<<i))//a、b二进制不同的位
                break;
        for(auto& n : nums)
        {
            if((n>>i)&1)
                a ^= n;
            else
                b ^= n;
        }
        for(int j = 1; j <= nums.size()+2; ++j)
        {
            if((n>>i)&1)
                a ^= j;
            else
                b ^= j;
        }
        return {a,b};
    }
};