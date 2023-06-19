class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int a=0,maxi=0;
        for(auto it:gain)
        {
            maxi=max(maxi,a+it);
             a=a+it;
    
        }
        return maxi;
    }
};