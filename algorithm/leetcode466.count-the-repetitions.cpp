class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    	if(n1*s1.size() < n2*s2.size())
    		return 0;
    	int len1 = s1.size(), len2 = s2.size(), cnt1 = 0, cnt2 = 0, i, j=0;
    	unordered_map<int,pair<int,int>> m;//j, cnt1, cnt2
    	while(cnt1 < n1)
    	{
    		for(i = 0; i < len1; ++i)
    		{
    			if(s1[i]==s2[j])
    				j++;
    			if(j==len2)
    				j=0,cnt2++;
    		}
    		cnt1++;
    		if(!m.count(j))
    			m[j] = make_pair(cnt1, cnt2);
    		else
    		{
    			int lastcnt1 = m[j].first;
    			int lastcnt2 = m[j].second;
    			int gap1 = cnt1-lastcnt1;
    			int gap2 = cnt2-lastcnt2;
    			int num = (n1-cnt1)/gap1;
    			cnt1 += num*gap1;
    			cnt2 += num*gap2;
    		}
    	}
    	return cnt2/n2;
    }
};