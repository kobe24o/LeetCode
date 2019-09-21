class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> s;
        string odd, even;
        int i, j;
        for(i = 0; i < A.size(); ++i)
        {
        	even = odd = "";
        	for(j = 0; j < A[i].size(); ++j)
        	{
        		if(j%2)
        			odd.push_back(A[i][j]);
        		else
        			even.push_back(A[i][j]);
        	}
        	sort(odd.begin(), odd.end());
        	sort(even.begin(), even.end());
        	s.insert(odd+even);
        }
        return s.size();
    }
};