class Cashier {
	int num;
	int disc;
	vector<int> pric;
	unordered_map<int,int> idx;
	int people = 0;
    int i;
    double money;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
    	num = n;
    	disc = discount;
    	pric = prices;
    	for(i = 0; i < products.size();++i)
    	{
    		idx.insert(make_pair(products[i],i));
    	}
    }
    
    double getBill(vector<int> product, vector<int> amount) {
    	money = 0;
    	for(i = 0; i < product.size(); i++)
    	{
    		money += pric[idx[product[i]]]*amount[i];
    	}
    	people++;
    	if(people == num)
    	{
    		people = 0;
    		money = money*(100-disc)/100;
    	}
    	return money;
    }
};