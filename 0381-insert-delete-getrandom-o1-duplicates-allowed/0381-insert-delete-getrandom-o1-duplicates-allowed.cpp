class RandomizedCollection {
public:
    map<int,set<int>> mp;
    vector<int> arr;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        arr.push_back(val);                          
        mp[val].insert(arr.size()-1);                  
        return mp[val].size() == 1;
        
    }
    
    bool remove(int val) {
        
        auto it=mp.find(val);
        if(it!=mp.end())
        {
            auto pos= *it->second.begin();
            it->second.erase(it->second.begin());
            
            arr[pos]=arr.back();
            mp[arr.back()].insert(pos);
            mp[arr.back()].erase(arr.size()-1);
            arr.pop_back();
            
            if(it->second.size()==0) mp.erase(it);
            
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
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */