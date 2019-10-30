class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        bool allZero = true;
        for(int num:nums) 
    	{
    		vec.push_back(to_string(num));
    		if(num != 0)
    			allZero = false;
    	}
    	if(allZero)
    		return "0";
        sort(vec.begin(), vec.end(), 
        		[](string &a, string &b){ return a+b > b+a; });
        string ans;
        for(string s:vec)
        	ans += s;
        return ans;
    }
};