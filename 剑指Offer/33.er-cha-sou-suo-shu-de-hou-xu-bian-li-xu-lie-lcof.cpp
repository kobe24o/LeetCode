class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
    	if(postorder.size() <= 2)
    		return true;
        return check(postorder,0,postorder.size()-1);
    }

    bool check(vector<int>& order, int L, int R) 
    {
    	if(L >= R)//区间只有1个或者没有元素了
    		return true;
    	int root = order[R];//根
    	int i = L, j = R-1;//左子树的区间指针i，右子树j
    	while(i < R && order[i] < root)
    		i++;
    	while(j >= L && order[j] > root)
    		j--;
    	if(i-j != 1)//最终j应该紧贴i的左侧
    		return false;
    	return check(order,L,i-1) && check(order,j+1,R-1);
    	//递归查找2侧子树
    }
};