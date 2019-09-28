class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool visited[rooms.size()] = {false};
        dfs(visited, rooms, 0);
        for(int i = 0; i < rooms.size(); ++i)
        {
        	if(visited[i] == false)
        		return false;
        }
        return true;
    }
    void dfs(bool *visited, vector<vector<int>> &rooms, int i)
    {
    	visited[i] = true;
    	for(int key = 0; key < rooms[i].size(); ++key)
    	{
    		if(!visited[rooms[i][key]])
    			dfs(visited, rooms, rooms[i][key]);
    	}
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool visited[rooms.size()] = {false};
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int key, roomID, i;
        while(!q.empty())
        {
        	roomID = q.front();
        	q.pop();
        	for(i = 0; i < rooms[roomID].size(); ++i)
        	{
        		key = rooms[roomID][i];
        		if(!visited[key])
        		{
        			q.push(key);
        			visited[key] = true;
        		}
        	}
        }
        for(int i = 0; i < rooms.size(); ++i)
        {
        	if(visited[i] == false)
        		return false;
        }
        return true;
    }
};