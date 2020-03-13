class Solution {
public:
    int killMonster(int n, vector<vector<int>> &v) {
        vector<int> ot = v[0];//奥特曼
        queue<vector<int>> q;
        int count = 0, i;
        for(i = 1; i < v.size(); ++i)
            q.push(v[i]);//怪兽队列
        vector<int> tp;
        bool eat = true;
        while(eat)
        {
            eat = false;
            for(i = 0; i < q.size(); ++i)
            {
                tp = q.front();
                if(ot[0]>=tp[0]&&ot[1]>=tp[1]&&ot[2]>=tp[2]&&ot[3]>=tp[3]&&ot[4]>=tp[4])
                {
                    count++;
                    eat = true;
                    q.pop();//吃了，删掉怪兽
                    ot[0] += tp[0];//属性加上
                    ot[1] += tp[1];
                    ot[2] += tp[2];
                    ot[3] += tp[3];
                    ot[4] += tp[4];
                    break;//重新扫描队列
                }
                else
                {
                    q.push(tp);//回到队尾
                    q.pop();
                }
            }
            if(eat == false)//一轮下来没吃着
                break;//打败不了任何一个，退出
        }
        return count;
    }
};