class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> set;
        for (int i = 0; i < A.size(); ++i)
        {
        	if(set.find(A[i]) == set.end())
        		set.insert(A[i]);
        	else
        		return A[i];
        }
        return -1;
    }
};