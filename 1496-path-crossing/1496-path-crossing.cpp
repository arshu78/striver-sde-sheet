class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int,int>> v;
        int i=0,j=0;
        v.push_back({i,j});
        for(auto it:path)
        {
            if(it=='N') i--;
            else if(it=='S') i++;
            else if(it=='E') j++;
            else j--;
            
            v.push_back({i,j});
        }
        set<pair<int,int>> st(v.begin(),v.end());
        if(v.size()==st.size()) return false;
        
        return true;
    }
};