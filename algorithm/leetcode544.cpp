class Solution {
public:
    string findContestMatch(int n) {
        int l = 1, r = n, t = 0;
        while(n>1)
        {
        	t++;//比赛几轮结束
        	n >>= 1;
        }
        vector<string> ans, temp;
        while(l < r)
        	ans.push_back("("+to_string(l++)+","+to_string(r--)+")");
        while(--t)
        {
        	l = 0, r = ans.size()-1;
        	while(l < r)
        		temp.push_back("("+ans[l++]+","+ans[r--]+")");
        	ans = temp;
        	temp.clear();
        }
        return ans[0];
    }
};