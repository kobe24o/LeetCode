class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() < 2 || B.size() < 2 || A.size() != B.size())
        	return false;
        int countA[26] = {0}, countB[26] = {0}, diff = 0;
        for(int i = 0; i < A.size(); ++i)
        {
        	if(A[i] != B[i])
        		diff++;
            countA[A[i]-'a']++;
            countB[B[i]-'a']++;
        }
        for(int i = 0; i < 26; ++i)
            if(countA[i] != countB[i])
                return false;
        bool hasSameChar = false;
        for(int i = 0; i < 26; ++i)
        	if(countA[i] >= 2)
        	{
        		hasSameChar = true;
        		break;
        	}
        if(diff == 2 || (diff == 0 && hasSameChar))
        	return true;
        return false;
    }
};