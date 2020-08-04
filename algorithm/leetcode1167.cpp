class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> q;//小顶堆
        for(int i : sticks) 
        	q.push(i);
        int a, b, sum = 0;
        while(q.size() > 1)
        {
        	a = q.top();
        	q.pop();
        	b = q.top();
        	q.pop();
        	q.push(a+b);
        	sum += a+b;
        }
        return sum;
    }
};