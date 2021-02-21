class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), b = 0;
        vector<int> ans(n), temp(n);
        for(int i = 0; i < n; i++)
        {
            ans[i] += b + (i > 0 ? ans[i-1] : 0);
            if(boxes[i]=='1')
                b++;
        }
        b = 0;
        for(int i = n-1; i >= 0; i--)
        {
            temp[i] += b + (i < n-1 ? temp[i+1] : 0);
            if(boxes[i]=='1')
                b++;
            ans[i] += temp[i];
        }
        return ans;
    }
};