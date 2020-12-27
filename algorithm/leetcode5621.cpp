```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        for(int i = 0; i < n; i++) 
            q.push(i);//排队
        int prevsize, cursize, i = 0;
        while(1)
        {
            int k = q.size();
            prevsize = q.size();//开始取餐，人数
            while(k--)
            {
                int id = q.front();
                q.pop();
                if(students[id] == sandwiches[i])
                {   //喜欢吃
                    i++;//餐被取走
                }
                else
                {
                    q.push(id);//不喜欢吃，排到队尾
                }
            }
            cursize = q.size();
            if(cursize == prevsize)//没有人吃到午餐，结束
                break;
        }
        return q.size();
    }
};
```
8 ms    8.8 MB  C++