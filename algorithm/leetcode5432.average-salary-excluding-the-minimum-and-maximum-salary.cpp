class Solution {
public:
    double average(vector<int>& salary) {
        int MAX = *max_element(salary.begin(), salary.end());
        int MIN = *min_element(salary.begin(), salary.end());
        int sum = accumulate(salary.begin(), salary.end(),0);
        return (sum-MAX-MIN)/double(salary.size()-2);
    }
};