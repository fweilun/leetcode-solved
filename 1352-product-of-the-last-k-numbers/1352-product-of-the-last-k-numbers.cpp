class ProductOfNumbers {
public:
    ProductOfNumbers() {
        store.push_back(1);
    }
    
    void add(int num) {
        if (!num){
            num=1;
            lastZero=0;
            temp=1;
        }
        ++lastZero;
        temp*=num;
        store.push_back(temp);
    }
    
    int getProduct(int k) {
        int n=store.size();
        if (lastZero <= k) return 0;
        return store[n-1]/store[n-k-1];
    }
    vector<long long> store;
    int lastZero=1; // 1 是最近
    long long temp=1;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */