class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(7, 0);
        for(int i = 0; i < n; i++) 
        {
            count[A[i]]++;//计数
            count[B[i]]++;
        }
        int num = -1;
        for(int i = 1; i <= 6; ++i)
        {
            if(count[i] >= n)//个数达标的数
                num = i;
        }
        if(num == -1)
            return -1;
        int rotation = 0, notrotation = 0;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] == num && B[i] == num)
                notrotation++;//两个都是，不需要交换
            else if(A[i] != num && B[i] != num)
                return -1;//都不等，不存在
            else if(A[i] == num)
                rotation++;
        }
        return min(rotation, n-notrotation-rotation);
    }
};