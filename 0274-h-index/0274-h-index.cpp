class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        
        int ans=0;
        int size=citations.size();
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=size - i) ans++;
        }
        return ans;
    }
};