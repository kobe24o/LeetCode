class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i = citations.size()-1, papers = 0;
        while(i >= 0 && papers < citations[i])
        {
            papers++;
            i--;
        }
        return papers;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size()-1, mid, n = citations.size();
        //找第一个citations[i] >= n-i
        while(l <= r)
        {
        	mid = l +((r-l)>>1);
        	if(citations[mid] < n-mid)
        		l = mid+1;
        	else if(citations[mid] >= n-mid)
        	{
        		if(mid==0 || citations[mid-1] < n-mid)
        			return n-mid;
        		r = mid-1;
        	}
        }
        return n-l;
    }
};