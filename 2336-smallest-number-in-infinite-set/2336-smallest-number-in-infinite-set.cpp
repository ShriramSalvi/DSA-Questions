class SmallestInfiniteSet {
public:
    set<int>st;
    SmallestInfiniteSet() {
       for(int i=1; i<=1000; i++){
        this->st.insert(i);
       } 
    }
    
    int popSmallest() {
       if(!(this->st.empty()))
       {int minimum = *(this->st.begin());
       this->st.erase(minimum);
       return minimum;
       }
       return 1;
    }
    
    void addBack(int num) {
        this->st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */