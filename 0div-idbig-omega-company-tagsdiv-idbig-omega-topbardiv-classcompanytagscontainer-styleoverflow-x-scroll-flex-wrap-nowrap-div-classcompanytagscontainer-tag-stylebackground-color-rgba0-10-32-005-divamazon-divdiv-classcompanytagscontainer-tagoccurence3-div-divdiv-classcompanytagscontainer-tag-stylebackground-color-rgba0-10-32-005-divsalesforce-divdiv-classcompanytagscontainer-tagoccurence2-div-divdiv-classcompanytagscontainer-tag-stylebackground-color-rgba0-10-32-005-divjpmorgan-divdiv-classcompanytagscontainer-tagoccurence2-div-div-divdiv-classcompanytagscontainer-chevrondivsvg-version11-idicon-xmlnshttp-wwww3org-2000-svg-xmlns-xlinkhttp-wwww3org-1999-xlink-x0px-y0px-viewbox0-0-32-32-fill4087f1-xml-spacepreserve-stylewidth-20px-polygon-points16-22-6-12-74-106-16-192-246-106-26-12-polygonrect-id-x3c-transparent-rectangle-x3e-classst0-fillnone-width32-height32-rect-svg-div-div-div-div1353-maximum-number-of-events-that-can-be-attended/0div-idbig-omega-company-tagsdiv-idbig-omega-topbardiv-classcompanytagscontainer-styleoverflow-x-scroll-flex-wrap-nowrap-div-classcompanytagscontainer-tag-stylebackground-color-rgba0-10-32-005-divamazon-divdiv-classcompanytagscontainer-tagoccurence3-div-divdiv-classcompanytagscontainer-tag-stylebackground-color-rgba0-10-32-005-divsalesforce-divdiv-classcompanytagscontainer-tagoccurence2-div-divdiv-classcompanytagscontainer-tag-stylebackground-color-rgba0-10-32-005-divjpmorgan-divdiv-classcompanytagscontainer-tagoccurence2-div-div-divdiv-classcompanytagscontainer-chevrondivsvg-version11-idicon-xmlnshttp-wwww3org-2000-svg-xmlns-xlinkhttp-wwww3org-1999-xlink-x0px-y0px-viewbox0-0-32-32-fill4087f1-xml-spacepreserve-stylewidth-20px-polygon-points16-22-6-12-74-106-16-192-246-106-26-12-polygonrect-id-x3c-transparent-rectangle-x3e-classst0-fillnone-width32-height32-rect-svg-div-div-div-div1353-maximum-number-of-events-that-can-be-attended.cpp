class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[1]==b[1])
        {
            return a[0]<=b[0];
        }
      return a[1]<=b[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        int ans=0;
       
        set<int> st;
        for(int i=1;i<=100000;i++)
        {
            st.insert(i);
        }
        
        for(auto it:events)
        {
            int s=it[0],e=it[1];
            
            auto a=st.lower_bound(s);
            if(a==st.end() || *a>e) continue;
            else
            {
                ans++;
                st.erase(a);
            }
        }
        return ans;
    }
};