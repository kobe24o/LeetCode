class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
    	unordered_map<int,vector<int>> m;//文档片段，含有该片段的文档id
    	for(int i = 0; i < docs.size(); ++i)
    	{
    		for(int part : docs[i])
    			m[part].push_back(i);
    	}
    	unordered_map<int,unordered_map<int,int>> countSame;//doc1，doc2，sameValue
    	int i, j, id1, id2, num;
    	for(auto& mi : m)
    	{
    		for(i = 0; i < mi.second.size()-1; ++i)
    		{
    			id1 = mi.second[i];
    			for(j = i+1; j < mi.second.size(); ++j)
    			{
    				id2 = mi.second[j];
    				countSame[id1][id2] += 1;
    			}
    		}
    	}
    	vector<string> ans;
    	double similarity;
    	for(auto& vals : countSame)
    	{
    		id1 = vals.first;
    		for(auto& count : vals.second)
    		{
    			id2 = count.first;
    			num = count.second;
    			similarity = double(num)/(docs[id1].size()+docs[id2].size()-num);
    			char res[16];
    			sprintf(res, "%d,%d: %.4f", id1, id2, similarity+1e-9);
    			ans.push_back(string(res,res+16));
    		}
    	}
    	return ans;
    }
};