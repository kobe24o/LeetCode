class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1)
            return 1.0;//一个点
        if(target == 1)//多个点，最终目标不可能在1
            return 0;
        bool visited[n+1] = {false};
        queue<pair<int,double>> q;//idx, 概率
        int size, count;
        pair<int,double> tp;
        double prob = 1;
        bool found = false, noway = true;
        q.push({1,1.0});
        visited[1] = true;
        while(!q.empty())
        {
            size = q.size();
            t--;
            while(size--)
            {
                tp = q.front();
                q.pop();
                count = 0;//tp连接着多少个未访问的点
                for(auto& e : edges)
                {
                    if((e[0] == tp.first && !visited[e[1]]) || (e[1]==tp.first &&  !visited[e[0]]) )
                    {
                        if(e[1] == target || e[0] == target)
                            found = true;//找到 target
                        count++;//计数
                    }
                }
                for(auto& e : edges)
                {
                    if((e[0] == tp.first && !visited[e[1]]) || (e[1]==tp.first &&  !visited[e[0]]) )
                    {	//将连接的点加入队列，并计算概率
                        if(!visited[e[1]])
                        {
                            q.push({e[1], tp.second/count});
                            visited[e[1]] = true;
                        }
                        else{
                            q.push({e[0], tp.second/count});
                            visited[e[0]] = true;
                        };
						// 如果是 target，获取答案概率
                        if(e[1] == target || e[0] == target)
                            prob = tp.second/count;
                    }
                }
                noway = true;//target 下面还有连接点吗？
                if(found)
                {
                    for(auto& e : edges)
                    {
                        if(((e[0] == target && !visited[e[1]]))||(e[1]==target && !visited[e[0]]))
                        {	//有未访问的，则有路
                            noway = false;
                            break;
                        }
                    }
                }
            }
            if(found)
            {
                if(t==0)//时间到了，刚好找到
                    return prob;
                else if(t < 0)//时间不够，不可能到达
                    return 0;
                else	//时间够
                {
                    if(noway)//没有路，青蛙停留在target
                       return prob;
                    return 0;//有路，青蛙肯定走过去了，在target 概率 0
                }
            }
        }
        return prob;
    }
};