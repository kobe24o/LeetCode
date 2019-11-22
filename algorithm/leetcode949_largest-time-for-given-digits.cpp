class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int ans = -1, i, j, k, l, hours, mins;
        string h,m;
        for(i = 0; i < 4; i++)
            for(j = 0; j < 4; j++)
                if (j != i)
                    for(k = 0; k < 4; k++)
                        if (k != i && k != j)
                        {
                            l = 6 - i - j - k;
                            hours = 10*A[i] + A[j];
                            mins = 10*A[k] + A[l];
                            if(hours < 24 && mins < 60 && (hours*60+mins > ans))
                            {
                                ans = hours*60 + mins;
                                h = hours>=10 ? to_string(hours) : ("0"+to_string(hours));
                                m = mins>=10 ? to_string(mins) : ("0"+to_string(mins));
                            }
                        }
        if(ans >= 0) 
            return h+":"+m;
        return "";
    }
};

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        vector<string> ans;
        string s;
        int i;
        do
        {
            if( ( (A[0]==2 && A[1]<4) || A[0]<2) && A[2]<6 ) 
            {
                s = "";
                for(i = 0; i < 4; i++)
                    s += (A[i]+'0');
                s.insert(2, ":");
                return s;
            }
        }
        while(prev_permutation(A.begin(), A.end()));
        return "";
    }
};