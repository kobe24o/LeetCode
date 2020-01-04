class Solution {
public:
    string getPermutation(int n, int k) {
        string ans, temp;
        bool visited[10] = {0};
        int count = 0;
        permute(n, k, count, 0, temp, ans, visited);
        return ans;
    }

    void permute(int &n, int &k, int& count, int bit, string &temp, string &ans, bool* visited)
    {
    	if(count > k)
    		return;
    	if(bit == n)
    	{
    		count++;
    		if(count == k)
    			ans = temp;
    	}
    	for(int i = 1; i <= n; i++)
    	{
    		if(visited[i])
    			continue;
    		temp.push_back(i+'0');
    		visited[i]=true;
    		permute(n, k, count, bit+1, temp, ans, visited);
    		temp.pop_back();
    		visited[i]=false;
    	}
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        int factor[10] = {1,1,2,6,24,120,720,5040,40320,362880};//阶乘数
        string num = "123456789";
        string ans;
        int bit;
        while(n > 0)
        {
        	bit = (k-1)/factor[n-1];
        	ans.push_back(num[bit]);
        	num.erase(num.begin()+bit);//该位数写入答案了，删除
        	k -= bit*factor[n-1];
        	n--;
        }
        return ans;
    }
};