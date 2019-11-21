class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int count = 1, i;
        vector<int> startP;
        for(i = 0; i < A.size(); ++i)
        	if(A[i] == B[0])
        		startP.push_back(i);
        string str(A), temp;
        for(int i : startP)
        {
        	while(str.size()-i < B.size())
	        {
	        	str.append(A);
	        	count++;
	        }
	        temp = str.substr(i,B.size());
	        if(temp == B)
	        	return count;
        }
        return -1;
    }
};


class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string str(A);
        int count = 1;
        while(str.size() < B.size()) 
        {
            str.append(A);
            ++count;
        }
        if(str.find(B) != string::npos)
            return count;
        str.append(A);
        ++count;
        if(str.find(B) != string::npos)
            return count;
        return -1;
    }
};