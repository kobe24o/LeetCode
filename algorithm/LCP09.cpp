class Solution {
public:
    int minJump(vector<int>& jump) {
        int i, n = jump.size(), t = 0, size, tp, prevPos = 0;
        vector<bool> vis(n,false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            size = q.size();
            t++;
            while(size--)
            {
                tp = q.front();
                q.pop();
                if(tp+jump[tp] >= n)
                    return t;
                if(!vis[tp+jump[tp]])
                {   //向右跳过来
                    q.push(tp+jump[tp]);
                    vis[tp+jump[tp]] = true;
                }
                for(i = prevPos+1; tp >0 && i < tp; ++i)
                {   //向左位置跳
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i] = true;
                    }
                }
                prevPos = max(prevPos,tp);//没有这句会超时
            }
        }
        return t;
    }
};