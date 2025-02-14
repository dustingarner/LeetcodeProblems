class ProductOfNumbers {
public:
    vector<int> numbers;
    vector<int> products = {1};
    int recentZero = -1;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        numbers.push_back(num);
        if(num == 0){
            recentZero = numbers.size() - 1;
            products = {1};
            return;
        }
        products.push_back(products[products.size()-1] * num);
    }
    
    int getProduct(int k) {
        if(int(numbers.size()-k) <= recentZero){
            return 0;
        }
        return products[products.size()-1] / products[products.size()-k-1];
    }
};
