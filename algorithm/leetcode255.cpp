class Solution {
	map<int,int> m;
public:
    bool verifyPreorder(vector<int>& preorder) {
    	if(preorder.size() <= 2) return true;
    	int MIN = INT_MIN;
    	stack<int> s;
    	for(int i = 0; i < preorder.size(); ++i)
    	{
    		if(preorder[i] < MIN)
    			return false;
    		while(!s.empty() && s.top() < preorder[i])//遇到大的了，右分支
    		{
    			MIN = s.top();
    			s.pop();
    		}
    		s.push(preorder[i]);
    	}
    	return true;
    }
};