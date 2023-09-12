class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.count(val))
        {
            return false;
        }
        
        arr.push_back(val);
        int index=arr.size()-1;
        
        mp[val]=index;
        
        return true;
        
    }
    
    bool remove(int val) {
        
        if(mp.count(val))
        {
             int index=mp[val];
            int v=arr.back();
            
            arr[index]=v;
            mp[v]=index;
            arr.pop_back();
            mp.erase(val);
            return true;
        }
      
           return false;
        
    }
    
    int getRandom() {
        int randomindex= rand() % arr.size();
                return arr[randomindex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */