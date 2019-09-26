#include<unordered_set>
#include<string>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.find("0000") != dead.end())
            return -1;
        unordered_set<string> visited;
        queue<string> q;
        string tp, tp_1, tp_2;
        int step = 0, n, i;
        vector<int> dir = {1,-1};
        q.push("0000");
        visited.insert("0000");
        while(!q.empty()) 
        {
        	n = q.size();
        	while(n--)
        	{
        		tp = q.front();
        		q.pop();
        		if(tp == target)
        			return step;
        		for(i = 0; i < 4; ++i)
        		{
                    tp_1 = tp_2 = tp;
	                tp_1[i] = tp_1[i] == '9' ? '0' : tp_1[i]+1;
    				tp_2[i] = tp_2[i] == '0' ? '9' : tp_2[i]-1;
    				if(visited.find(tp_1) == visited.end() && dead.find(tp_1) == dead.end())
    				{
    					visited.insert(tp_1);
    					q.push(tp_1);
    				}
                    if(visited.find(tp_2) == visited.end() && dead.find(tp_2) == dead.end())
                    {
                        visited.insert(tp_2);
                        q.push(tp_2);
                    }
        		}
        	}
        	++step;
        }
        return -1;
    }
};

int main()
{
	Solution s;
	vector<string> d = {"8888"};
	s.openLock(d,"0009");
}