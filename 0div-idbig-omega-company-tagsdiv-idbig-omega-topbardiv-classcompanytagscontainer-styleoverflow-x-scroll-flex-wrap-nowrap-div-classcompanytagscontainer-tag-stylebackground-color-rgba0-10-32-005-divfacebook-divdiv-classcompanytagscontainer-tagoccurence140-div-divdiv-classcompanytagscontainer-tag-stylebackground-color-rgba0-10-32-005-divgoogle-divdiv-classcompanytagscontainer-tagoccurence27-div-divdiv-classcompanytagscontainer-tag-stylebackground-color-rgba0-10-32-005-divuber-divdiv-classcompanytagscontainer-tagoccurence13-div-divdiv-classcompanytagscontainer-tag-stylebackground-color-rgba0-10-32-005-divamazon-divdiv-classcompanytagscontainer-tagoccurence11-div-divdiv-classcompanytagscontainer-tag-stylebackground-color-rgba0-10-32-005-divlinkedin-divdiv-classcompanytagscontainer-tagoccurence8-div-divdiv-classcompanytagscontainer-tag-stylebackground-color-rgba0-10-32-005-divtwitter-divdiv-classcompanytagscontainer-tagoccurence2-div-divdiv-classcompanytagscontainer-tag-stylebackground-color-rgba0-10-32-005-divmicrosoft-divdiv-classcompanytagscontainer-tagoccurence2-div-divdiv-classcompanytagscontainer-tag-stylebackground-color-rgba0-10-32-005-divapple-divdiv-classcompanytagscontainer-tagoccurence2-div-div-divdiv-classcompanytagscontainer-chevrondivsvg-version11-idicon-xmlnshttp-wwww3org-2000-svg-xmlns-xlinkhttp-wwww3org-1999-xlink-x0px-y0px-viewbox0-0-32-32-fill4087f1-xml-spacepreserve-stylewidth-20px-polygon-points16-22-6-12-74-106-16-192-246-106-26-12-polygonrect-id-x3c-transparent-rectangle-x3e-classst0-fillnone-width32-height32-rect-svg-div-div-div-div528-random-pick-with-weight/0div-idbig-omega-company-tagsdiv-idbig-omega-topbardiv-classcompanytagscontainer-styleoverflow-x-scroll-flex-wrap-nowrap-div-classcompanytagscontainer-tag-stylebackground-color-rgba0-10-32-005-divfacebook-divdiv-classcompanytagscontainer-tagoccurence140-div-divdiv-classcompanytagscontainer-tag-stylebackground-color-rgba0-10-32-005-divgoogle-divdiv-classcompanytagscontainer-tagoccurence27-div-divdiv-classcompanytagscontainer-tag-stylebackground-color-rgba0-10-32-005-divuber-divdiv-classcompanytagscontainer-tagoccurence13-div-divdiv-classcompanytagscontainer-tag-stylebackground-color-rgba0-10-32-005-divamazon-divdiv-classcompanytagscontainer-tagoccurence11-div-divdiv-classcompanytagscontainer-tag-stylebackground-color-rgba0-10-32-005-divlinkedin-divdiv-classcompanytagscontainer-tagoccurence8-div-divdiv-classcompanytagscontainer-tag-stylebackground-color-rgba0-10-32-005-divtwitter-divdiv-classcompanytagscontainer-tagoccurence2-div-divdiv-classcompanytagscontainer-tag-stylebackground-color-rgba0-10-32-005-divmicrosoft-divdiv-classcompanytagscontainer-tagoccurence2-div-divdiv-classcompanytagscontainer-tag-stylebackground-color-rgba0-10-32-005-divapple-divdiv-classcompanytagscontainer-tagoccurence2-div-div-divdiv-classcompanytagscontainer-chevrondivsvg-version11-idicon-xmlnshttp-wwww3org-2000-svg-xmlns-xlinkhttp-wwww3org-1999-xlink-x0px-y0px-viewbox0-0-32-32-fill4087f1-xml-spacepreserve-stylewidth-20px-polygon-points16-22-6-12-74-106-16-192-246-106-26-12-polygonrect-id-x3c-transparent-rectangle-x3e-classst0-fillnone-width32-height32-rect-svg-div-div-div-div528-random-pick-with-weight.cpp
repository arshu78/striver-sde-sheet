class Solution {
public:
    vector<int> w;
    int max;
    Solution(vector<int>& w) {
        for(int i=1;i<w.size();i++)
        {
            w[i]=w[i-1] + w[i];
        }
        max=w[w.size()-1];
        
        this->w=w;
    }
    
    int pickIndex() {
        int low=0,high=w.size()-1;
        int target=1 + (rand() % max);
        
        while(low<=high)
        {
            int mid=(low+high) /2;
            if(w[mid]==target) return mid;
            else if(w[mid] < target) low=mid+1;
            else high=mid-1;
        }
        
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */