class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int &a, int &b){return a > b;});
        int i = 0;
        while(i < citations.size() && citations[i] > i)
        	i++;
        return i;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int &a, int &b){return a > b;});
        //找最后一个citations[i] >= i+1
        int l = 0, r = citations.size()-1, mid;
        while(l <= r)
        {
        	mid = l + ((r-l)>>1);
        	if(citations[mid] < mid+1)
        		r = mid-1;
        	else
        	{
        		if(mid == citations.size()-1 || citations[mid+1] < mid+2)
        			return mid+1;
        		l = mid+1;
        	}
        }
        return l;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), i;
        int paper[n+1] = {0};
        for(i = 0; i < n; ++i)
        	paper[min(citations[i], n)]++;
        	//分数是下标分的，有多少篇(值)
        int count = n;//引用n次的
        int papers = paper[n];//文章总数papers
        while(count > papers)
        {
        	count--;
        	papers += paper[count];
        }
        return count;
    }
};