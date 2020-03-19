class AnimalShelf {
    queue<vector<int>> dog;
    queue<vector<int>> cat;
    vector<int> ans;
public:
    AnimalShelf() {}
    
    void enqueue(vector<int> animal) {
        if(animal[1] == 0)
            cat.push(animal);
        else
            dog.push(animal);
    }
    
    vector<int> dequeueAny() {
        if(!dog.empty() && cat.empty())
            return dequeueDog();
        else if(dog.empty() && !cat.empty())
            return dequeueCat();
        else if(dog.empty() && cat.empty())
            return {-1,-1};
        else
        {
            if(dog.front()[0] < cat.front()[0])
                return dequeueDog();
            return dequeueCat();
        }
    }
    
    vector<int> dequeueDog() {
        if(!dog.empty())
        {
            ans = dog.front();
            dog.pop();
            return ans;
        }
        return {-1,-1};
    }
    
    vector<int> dequeueCat() {
        if(!cat.empty())
        {
            ans = cat.front();
            cat.pop();
            return ans;
        }
        return {-1,-1};
    }
};