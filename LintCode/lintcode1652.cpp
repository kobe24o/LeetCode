/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    vector<int> intervalXOR(vector<int> &A, vector<Interval> &query) {
        int s = 0;
        A.insert(A.begin(),0);
        A.push_back(0);
        for(int i = 0; i < A.size(); ++i)
        {
        	s ^= A[i];
        	A[i] = s;
        }
        vector<int> ans;
        for(int i = 0; i < query.size(); ++i)
        {
        	ans.push_back(A[query[i].start]^A[query[i].start+query[i].end]);
        }
        return ans;
    }
};