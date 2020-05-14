class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	unordered_map<int,unordered_set<int>> m;
    	vector<int> indegree(numCourses,0);
    	for(auto& pre : prerequisites)
    	{
    		m[pre[1]].insert(pre[0]);//完成1后，才能完成0
    		indegree[pre[0]]++;
    	}
    	queue<int> q;//入度为0的入队
    	for(int i = 0; i < numCourses; ++i)
    		if(indegree[i] == 0)
    			q.push(i);
		int finish = 0, tp;
		while(!q.empty())
		{
			tp = q.front();//tp完成了，依赖其的，入度都-1
			finish++;
			q.pop();
			for(auto id : m[tp])
			{
				indegree[id]--;
				if(indegree[id]==0)
				{
					q.push(id);
				}
			}
		}
		return finish == numCourses;
    }
};

class Solution {
    unordered_map<int,unordered_set<int>> m;
    enum {todo, doing, done};
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {	
    	vector<int> visited(numCourses,0);
    	for(auto& pre : prerequisites)
    		m[pre[1]].insert(pre[0]);//完成1后，才能完成0
        bool can = true;
    	for(int i = 0; i < numCourses; ++i)
    	{
            dfs(i, visited, can);
            if(!can)
                break;
        }
        return can;
    }

    void dfs(int i, vector<int> &visited, bool& can)
    {
        if(!can) return;
        if(visited[i]==done)
            return;
        if(visited[i]==doing)//还没done,又出现了doing，出现环
        {
            can = false;
            return;
        }
        visited[i] = doing;//进入下一个要做的之前是doing状态
        for(auto id : m[i])
        {
            dfs(id, visited, can);
        }
        visited[i] = done;//往回走的时候状态做完了
    }
};