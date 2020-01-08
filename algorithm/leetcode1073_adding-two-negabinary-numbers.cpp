class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size()-1, j = arr2.size()-1, carry = 0;
        vector<int> ans;
        while(i>=0 || j>=0 || carry)
        {
        	if(i >= 0)
        		carry += arr1[i--];
        	if(j >= 0)
        		carry += arr2[j--];
        	ans.push_back((carry+2)%(-2));
        	if(carry == -1)
        		carry = 1;
        	else
        		carry /= -2;
        }
        
        while(ans.size()>1 && ans.back() == 0)
        	ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};