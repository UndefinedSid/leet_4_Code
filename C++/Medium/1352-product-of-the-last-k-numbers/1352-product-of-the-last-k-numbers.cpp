class ProductOfNumbers {
public:
    using ll=long long;

    vector<ll> pref;
    ProductOfNumbers() {
        pref.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            pref.clear();
            pref.push_back(1);
        }else
            pref.push_back(pref.back() * num);
    }
    
    int getProduct(int k) {
       if(k >= pref.size()){
        return 0;
       }
       int prod=pref[pref.size()-1-k];
       return pref.back() / prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */