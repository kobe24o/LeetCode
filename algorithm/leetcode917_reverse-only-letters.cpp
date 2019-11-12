class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size()-1;
        while(i < j)
        {
        	while(i < S.size() && !isalpha(S[i]))
        		i++;
        	while(j >= 0 && !isalpha(S[j]))
        		j--;
        	if(i < j)
        		swap(S[i++],S[j--]);
        }
        return S;
    }
};