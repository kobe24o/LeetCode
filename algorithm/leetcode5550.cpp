class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0)
        {
            vector<int> ans(n, 0);
            return ans;
        }
        vector<int> temp(code);
        for(auto c : code)
            temp.push_back(c);
        vector<int> presum(n, 0), tailsum(n, 0);
        if(k < 0)
        {
            k = -k;
            int sum = 0;
            for(int i = n-k; i < n; i++)
                sum += temp[i];
            for(int i = n; i < 2*n; i++)
            {
                presum[i-n] = sum;
                sum -= temp[i-k];
                sum += temp[i];
            }
            return presum;
        }
        else
        {
            int sum = 0;
            for(int i = n-1+k; i >= n; i--)
                sum += temp[i];
            for(int i = n-1; i >= 0; i--)
            {
                tailsum[i] = sum;
                sum -= temp[i+k];
                sum += temp[i];
            }
            return tailsum;
        }
    }
};