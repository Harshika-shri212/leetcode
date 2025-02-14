class ProductOfNumbers {
public:
     vector<int> v;
    ProductOfNumbers() {
        v.clear();
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        if (k > (int)v.size()) return 0; 

        int prod = 1;
        int start = v.size() - k; 

        for (int i = v.size() - 1; i >= start; i--) {
            prod *= v[i];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */