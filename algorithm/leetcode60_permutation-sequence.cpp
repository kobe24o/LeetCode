class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        bool found = false;
        permute(n, k, 0, ans, found);
        return ans;
    }

    void permute(int &n, int &k, int count, string &ans, bool &found)
    {
    	if(found)
    		return;
    	if(count == n)
    	{
    		found = true;
    		return;
    	}

    }
};