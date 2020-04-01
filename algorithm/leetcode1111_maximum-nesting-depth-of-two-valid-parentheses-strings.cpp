class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
    	int i, j = 0, depth = 0;
    	vector<int> ans(seq.size(),0);
    	for(i = 0; i < seq.size(); ++i,++j)
    	{
    		if(seq[i] == '(')
    			depth++;
    		else
    			depth--;
    		if(depth & 1)//奇数层
    			ans[j] = 1;
    	}
    	return ans;
    }
};