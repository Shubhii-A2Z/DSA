class ProductOfNumbers {
public:
    typedef long long ll;
    // vector<int> v;
    vector<int> prePrd;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        // v.push_back(num);
        if(num==0) prePrd.clear();
        else{
            if(prePrd.size()==0) prePrd.push_back(num);
            else prePrd.push_back(num*prePrd.back());
        }
    }
    
    int getProduct(int k) {
        if(k>prePrd.size()) return 0;
        if(k==prePrd.size()) return prePrd.back();
        return prePrd.back()/prePrd[prePrd.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */