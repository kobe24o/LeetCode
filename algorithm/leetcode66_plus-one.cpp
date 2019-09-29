class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, one = 1, s;
        vector<int> ans;
        for(i = digits.size() - 1; i >= 0; --i)
        {
        	s = digits[i]+one;
        	ans.push_back(s%10);
        	one = s/10;
        }
        if(one)
        	ans.push_back(1);
        return vector<int>(ans.rbegin(), ans.rend());
    }
};