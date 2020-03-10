class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int gap = 2*numRows-2;
        int startGap, i, j, k = 0;
        string ans(s.size(),'0');
        for(i = 0; i < numRows; i++) 
        {
            ans[k++] = s[i];
            startGap = gap-2*i;
            if(startGap==0)
                startGap = gap;
            for(j = i+startGap; j < s.size(); j += startGap)
            {
                ans[k++] = s[j];
                startGap = gap-startGap;
                if(startGap==0)
                    startGap = gap;
            }
        }
        return ans;
    }
};