class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    	unordered_map<int,multiset<int>> m;
    	for(int i = 0; i < B.size(); ++i)
    		m[B[i]].insert(i);
    	vector<int> ans(A.size());
    	for(int i = 0; i < A.size(); ++i)
    	{
    		ans[i] = *(m[A[i]].begin());
    		m[A[i]].erase(m[A[i]].begin());
    	}
    	return ans;
    }
};