class Solution {
public:
    int minDeletionSize(vector<string>& A) {
    	int n = A.size();
    	set<int> s, temp;//记录顺序未确定的
    	for(int i = 0; i < n; ++i) 
    		s.insert(i);
    	int del = 0;
    	for(int j = 0; j < n; ++j) 
    	{
    		bool order = true, equal = false;
    		char prev = 'a'-1;
    		int previd = -1;
    		for(auto i : s)
    		{
    			if(prev == A[i][j])
    			{
    				equal = true;
    				temp.insert(previd);
    				temp.insert(i);
    			}
    			else if(prev > A[i][j])
    			{
    				del++;
    				order = false;
    				break;
    			}
    			prev = A[i][j];
    			previd = i;
    		}
    		if(order && !equal)
    			break;
    		if(order && equal)
    		{
    			s = temp;
    			temp.clear();
    		}
    	}
    	return del;
    }
};