class Solution {
    int n;  //矩形个数
    int total;//总的点的个数
    int pointId;//选取的点的id
    vector<int> presum;//所有矩形点的个数的前缀和
    vector<vector<int>> rectsize;//矩形的高，宽
    vector<vector<int>> rects;//矩形
public:
    Solution(vector<vector<int>>& rects) {
        n = rects.size();
        presum.resize(n);
        rectsize.resize(n);
        this->rects = rects;
        int r, c;
        for(int i = 0; i < n; ++i)
        {
            r = rects[i][3]-rects[i][1]+1;//高
            c = rects[i][2]-rects[i][0]+1;//宽
            rectsize[i] = {r, c};
            presum[i] = r*c+(i>0 ? presum[i-1] : 0);//点个数的前缀和
        }
        total = presum.back();
    }
    
    vector<int> pick() {
        pointId = rand()%total + 1;//随机点
        int L = 0, R = n-1, mid, rectID;
        // 二分查找 presum， 找到第一个 >= pointId 的位置
        while(L <= R)
        {
            mid = L+((R-L)>>1);
            if(presum[mid] < pointId)
                L = mid+1;
            else
            {
                if(mid==0 || presum[mid-1] < pointId)
                {
                    rectID = mid;//找到该点所在的矩形ID
                    break;
                }
                else
                    R = mid-1;
            }
        }
        // idx 是该点在矩形内的id
        int idx = pointId - (rectID > 0 ? presum[rectID-1] : 0) - 1; 
        // 读取 矩形的 高， 宽
        int r = rectsize[rectID][0], c = rectsize[rectID][1];
        // 计算 相对左下角的偏移量
        int x = idx%c, y = idx/c;
        return {rects[rectID][0]+x, rects[rectID][1]+y};
    }
};