class FileSharing {
	priority_queue<int,vector<int>,greater<int>> numCanBeUsed;
	unordered_map<int,set<int>> user_file;
	unordered_map<int,set<int>> file_user;
public:
    FileSharing(int m) {
    	for(int i = 1; i <= m; ++i)
    		numCanBeUsed.push(i);
    }
    
    int join(vector<int> ownedChunks) {
    	if(numCanBeUsed.empty()) return -1;
    	int id = numCanBeUsed.top();//取号
    	numCanBeUsed.pop();
    	for(int f : ownedChunks)
    	{
    		user_file[id].insert(f);
    		file_user[f].insert(id);
    	}
    	return id;
    }
    
    void leave(int userID) {
    	numCanBeUsed.push(userID);
    	for(int f : user_file[userID])
            file_user[f].erase(userID);
    	user_file.erase(userID);
    }
    
    vector<int> request(int userID, int chunkID) {
    	vector<int> ans(file_user[chunkID].begin(), file_user[chunkID].end());
        if(!ans.empty() && !user_file[userID].count(chunkID))
        {	//如果文件存在，且 该用户没有该文件
            user_file[userID].insert(chunkID);
            file_user[chunkID].insert(userID);
        }
        return ans;
    }
};