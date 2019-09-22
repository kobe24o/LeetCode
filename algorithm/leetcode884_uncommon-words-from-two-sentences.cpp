class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> mA, mB;
        int i;
        string str;
        for(i = 0; i < A.size(); ++i)
        {
        	if(A[i] == ' ')
        	{
        		if(mA.find(str) == mA.end())
        			mA[str] = 1;
        		else
        			mA[str]++;
        		str = "";
        	}
        	else
        	{
        		str.push_back(A[i]);
        		if(i == A.size()-1)
        		{
        			if(mA.find(str) == mA.end())
        				mA[str] = 1;
        			else
        				mA[str]++;
        		}
        	}
        }
        str = "";
        for(i = 0; i < B.size(); ++i)
        {
        	if(B[i] == ' ')
        	{
        		if(mB.find(str) == mB.end())
        			mB[str] = 1;
        		else
        			mB[str]++;
        		str = "";
        	}
        	else
        	{
        		str.push_back(B[i]);
        		if(i == B.size()-1)
        		{
        			if(mB.find(str) == mB.end())
        				mB[str] = 1;
        			else
        				mB[str]++;
        		}
        	}
        }
        vector<string> ans;
        for(auto it = mA.begin(); it != mA.end(); ++it)
        {
        	if(it->second == 1 && mB.find(it->first) == mB.end())
        		ans.push_back(it->first);
        }
        for(auto it = mB.begin(); it != mB.end(); ++it)
        {
        	if(it->second == 1 && mA.find(it->first) == mA.end())
        		ans.push_back(it->first);
        }
        return ans;
    }
};