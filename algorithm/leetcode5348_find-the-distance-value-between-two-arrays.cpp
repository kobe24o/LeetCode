class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int i, j, count = 0;
        bool flag;
        for(i = 0; i < arr1.size(); i++) 
        {
            flag = true;
            for(j =0 ; j < arr2.size(); j++)
            {
                if(abs(arr1[i]-arr2[j]) <= d)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
        }
        return count;
    }
};