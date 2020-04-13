class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
    	if(square1[1] > square2[1])
    		swap(square1,square2);//第一个的左下角y坐标更小
    	double cx1, cy1, cx2, cy2, r1, r2;
    	r1 = square1[2]/2.0;
    	r2 = square2[2]/2.0;
    	cx1 = square1[0]+r1;//中心坐标
    	cy1 = square1[1]+r1;
    	cx2 = square2[0]+r2;
    	cy2 = square2[1]+r2;
    	if(cx1==cx2)//斜率无穷大
    		return {cx1,cy1-r1,cx1,max(cy1+r1,cy2+r2)};
    	else//斜率存在,分两种情况，与上下边相交，左右边相交
    	{
    		double k = (cy1-cy2)/(cx1-cx2);
    		double b = cy1-k*cx1;
            vector<vector<double>> points;
    		if(abs(k)>=1)//交点在上下边
    		{
    			points.push_back({(cy1+r1-b)/k, cy1+r1});
                points.push_back({(cy1-r1-b)/k, cy1-r1});
                points.push_back({(cy2+r2-b)/k, cy2+r2});
                points.push_back({(cy2-r2-b)/k, cy2-r2});
                sort(points.begin(),points.end());
                return {points.front()[0],points.front()[1],points.back()[0],points.back()[1]};
    		}
    		else//交点在左右边
    		{
    			points.push_back({cx1+r1, k*(cx1+r1)+b});
                points.push_back({cx1-r1, k*(cx1-r1)+b});
                points.push_back({cx2+r2, k*(cx2+r2)+b});
                points.push_back({cx2-r2, k*(cx2-r2)+b});
                sort(points.begin(),points.end());
                return {points.front()[0],points.front()[1],points.back()[0],points.back()[1]};
    		}
    	}
    }
};