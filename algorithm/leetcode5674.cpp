class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), i = 0, j = 0;
        string ans;
        ans.reserve(n1+n2);
        while(i < n1 || j < n2)
        {
            if(i < n1 && j < n2 && word1[i] > word2[j])
                ans.push_back(word1[i++]);
            else if(i < n1 && j < n2 && word1[i] < word2[j])
                ans.push_back(word2[j++]);
            else if(i < n1 && j < n2 && word1[i] == word2[j])
            {   //相等的情况下，往后找到不相等的
                int k1 = i, k2 = j;
                while(k1 < n1 && k2 < n2 && word1[k1] == word2[k2])
                    k1++, k2++;
                if((k1 < n1 && k2 < n2 && word1[k1] > word2[k2]) || k2==n2)
                    ans.push_back(word1[i++]);
                else //if((k1 < n1 && k2 < n2 && word2[k2] > word1[k1]) || k1==n1)
                    ans.push_back(word2[j++]);
            }
            else if(i < n1 && j == n2)
                ans.push_back(word1[i++]);
            else
                ans.push_back(word2[j++]);
            // cout << i << " " << j << endl;
        }
        return ans;
    }
};