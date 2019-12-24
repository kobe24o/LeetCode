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