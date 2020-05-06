class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int i, n = arr.size(), pos, nxt;
        vector<int> visited(n,false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty())
        {
            pos = q.front();
            if(arr[pos] == 0)
                return true;
            q.pop();
            nxt = pos-arr[pos];
            if(nxt >= 0 && !visited[nxt])
            {
                q.push(nxt);
                visited[nxt] = true;
            }
            nxt = pos+arr[pos];
            if(nxt < n && !visited[nxt])
            {
                q.push(nxt);
                visited[nxt] = true;
            }
        }
        return false;
    }
};