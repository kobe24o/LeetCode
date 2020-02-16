class ProductOfNumbers {
	vector<int> product;
	vector<int> tempList;
	int i, p;
public:
    ProductOfNumbers(){}
    
    void add(int num) {
        tempList.push_back(num);
    }
    
    int getProduct(int k) {
    	p = 1;
    	for(i = tempList.size()-1; i >= 0; --i)
    	{
    		tempList[i] *= p;
    		p = tempList[i];
    	}
    	for(i = 0; i < product.size(); ++i)
    		product[i] *= p;
    	for(i = 0; i < tempList.size(); ++i)
    		product.push_back(tempList[i]);
    	tempList.clear();
        return product[product.size()-k];
    }
};