class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0.0;
        for(int i=0; i< points.size(); i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                for(int k=j+1; k<points.size(); k++)
                {
                    // double a = sqrt((points[i][0]-points[j][0])*(points[i][0]-points[j][0])
                    //                     + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                    // double b = sqrt((points[j][0]-points[k][0])*(points[j][0]-points[k][0])
                    //                     + (points[j][1]-points[k][1])*(points[j][1]-points[k][1]));
                    // double c = sqrt((points[i][0]-points[k][0])*(points[i][0]-points[k][0])
                    //                     + (points[i][1]-points[k][1])*(points[i][1]-points[k][1]));
                    // 海伦公式：S = sqrt(p*(p-a)*(p-b)*(p-c)), p = (a+b+c)/2
                    // double p = (a+b+c)/2.0;
                    // double area = sqrt(p*(p-a)*(p-b)*(p-c));
                    
                    //坐标公式：S = |(x1 · y2 - x2 · y1) + (x2 · y3 - x3 · y2) + (x3 · y1 - x1 · y3)| / 2
                    double area = abs((points[i][0]*points[j][1] - points[j][0]*points[i][1])
                                     +(points[j][0]*points[k][1] - points[k][0]*points[j][1])
                                     +(points[k][0]*points[i][1] - points[i][0]*points[k][1])) / 2.0;
                    if(area > max_area)
                        max_area = area;
                }
            }
        }
        return max_area;
    }
};