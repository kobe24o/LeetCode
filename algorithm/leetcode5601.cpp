class OrderedStream {
    vector<string> arr;
    int ptr = 1;
public:
    OrderedStream(int n) {
        arr.resize(n+1);
    }
    
    vector<string> insert(int id, string value) {
        arr[id] = value;
        vector<string> ans;
        while(ptr < arr.size() && arr[ptr] != "") 
        {
            ans.push_back(arr[ptr]);
            ptr++;
        }
        return ans;
    }
};