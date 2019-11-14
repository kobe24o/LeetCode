class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> adj(N+1);//图有N个节点
        for(int i = 0; i < paths.size(); ++i)
        {
            adj[paths[i][0]].push_back(paths[i][1]);//将一条边加入图
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        unordered_set<int> flowers;
        vector<int> Node(N,-1);
        int i, j;
        for(i = 1; i <= N; ++i)//遍历N个邻接链
        {
            flowers = {1,2,3,4};
            for(j = 0; j < adj[i].size(); ++j)//相邻的都种了花了吗？
                if(Node[adj[i][j]-1] != -1)
                    flowers.erase(Node[adj[i][j]-1]);//种了，删除，这种花不能种了
            if(Node[i-1] == -1)//没有种植，在剩下的花里选一个，选begin
                Node[i-1] = *flowers.begin();
        }
        return Node;
    }
};