class Solution {
public:
    vector<int> findClosedNumbers(int num) {
    	vector<int> n(32,0);
    	int i = 31;
    	while(num)
    	{
    		n[i--] = num&1;
    		num >>= 1;
    	}
    	vector<int> ans(2,-1);
    	next_permutation(n.begin(),n.end());
    	long a = calnum(n);
    	if(a <= INT_MAX)
    		ans[0] = a;
    	prev_permutation(n.begin(), n.end());
    	prev_permutation(n.begin(), n.end());
    	a = calnum(n);
    	if(a <= INT_MAX)
    		ans[1] = a;
    	return ans;
    }

    int calnum(vector<int>& num)
    {
    	long sum = 0;
    	for(int i : num)
    		sum = sum*2+i;
    	return sum;
    }
};

class Solution {
public:
    vector<int> findClosedNumbers(int num) {
    	vector<int> n(32,0);
    	int i = 31;
    	while(num)
    	{
    		n[i--] = num&1;
    		num >>= 1;
    	}
    	vector<int> ans(2,-1);
    	next_perm(n);
    	long a = calnum(n);
    	if(0 < a && a <= INT_MAX)
    		ans[0] = a;
    	prev_perm(n);
    	prev_perm(n);
    	a = calnum(n);
    	if(0 < a && a <= INT_MAX)
    		ans[1] = a;
    	return ans;
    }
    void next_perm(vector<int>& n)
    {
    	int i = n.size()-2, j;
    	while(i>=0 && n[i] >= n[i+1])
    		i--;//找到下降点
    	j = i+1;
    	while(j < n.size() && n[i] < n[j])
    		j++;
    	swap(n[i],n[j-1]);
    	reverse(n,i+1,n.size()-1);
    }
    void next_perm(vector<int>& n)
    {
    	int i = n.size()-2, j;
    	while(i>=0 && n[i] <= n[i+1])
    		i--;//找到上升点
    	j = i+1;
    	while(j < n.size() && n[i] > n[j])
    		j++;
    	swap(n[i],n[j-1]);
    	reverse(n,i+1,n.size()-1);
    }
    void reverse(vector<int>& n, int l ,int r)
    {
    	while(l < r)
    		swap(n[l++],n[r--]);
    }
    int calnum(vector<int>& num)
    {
    	long sum = 0;
    	for(int i : num)
    		sum = (sum<<1)+i;
    	return sum;
    }
};

class Solution {
public:
    vector<int> findClosedNumbers(int num) {
    	bitset<32> big(num);
    	bitset<32> small(num);
    	vector<int> ans(2,-1);
    	int i, l, r;
    	for(i = 1; i < 32; ++i)//next 找下降点
    	{
    		if(big[i-1] > big[i])
    		{
    			big.flip(i);
    			big.flip(i-1);
    			l = 0, r = i-1;
    			while(l < r)
	    		{
	    			while(l < r && big[l]==1)//高位的1全部挪到低位
	    				l++;
	    			while(l < r && big[r]==0)
	    				r--;
	    			big.flip(l++);
    				big.flip(r--);
	    		}
	    		long a = big.to_ulong();
	    		if(a <= INT_MAX)
	    			ans[0] = a;
	    		break;
    		}
    	}
    	for(i = 1; i < 32; ++i)//prev 找上升点
    	{
    		if(small[i-1] < small[i])
    		{
    			small.flip(i);
    			small.flip(i-1);
    			l = 0, r = i-1;
    			while(l < r)
	    		{
	    			while(l < r && small[l]==0)//低位的1全部挪到高位
	    				l++;
	    			while(l < r && small[r]==1)
	    				r--;
	    			small.flip(l++);
    				small.flip(r--);
	    		}
	    		long a = small.to_ulong();
	    		if(a <= INT_MAX)
	    			ans[1] = a;
	    		break;
    		}
    	}
    	return ans;
    }
};