class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int n = 0;
        while(pow(2,n) <= label)
        	n++;
        while(n--)
        {
        	ans.push_back(label);
        	label = 3*pow(2,n-1)-1 - (label>>1);//左右边界和-label/2
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};