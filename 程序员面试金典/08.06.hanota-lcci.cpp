class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    	h(A,B,C,A.size());
    }
    
    void h(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        if(n == 1)
        {
        	C.push_back(A.back());
    		A.pop_back();
    		return;
        }
    	h(A,C,B,n-1);
    	C.push_back(A.back());
		A.pop_back();
    	h(B,A,C,n-1);
    }
};