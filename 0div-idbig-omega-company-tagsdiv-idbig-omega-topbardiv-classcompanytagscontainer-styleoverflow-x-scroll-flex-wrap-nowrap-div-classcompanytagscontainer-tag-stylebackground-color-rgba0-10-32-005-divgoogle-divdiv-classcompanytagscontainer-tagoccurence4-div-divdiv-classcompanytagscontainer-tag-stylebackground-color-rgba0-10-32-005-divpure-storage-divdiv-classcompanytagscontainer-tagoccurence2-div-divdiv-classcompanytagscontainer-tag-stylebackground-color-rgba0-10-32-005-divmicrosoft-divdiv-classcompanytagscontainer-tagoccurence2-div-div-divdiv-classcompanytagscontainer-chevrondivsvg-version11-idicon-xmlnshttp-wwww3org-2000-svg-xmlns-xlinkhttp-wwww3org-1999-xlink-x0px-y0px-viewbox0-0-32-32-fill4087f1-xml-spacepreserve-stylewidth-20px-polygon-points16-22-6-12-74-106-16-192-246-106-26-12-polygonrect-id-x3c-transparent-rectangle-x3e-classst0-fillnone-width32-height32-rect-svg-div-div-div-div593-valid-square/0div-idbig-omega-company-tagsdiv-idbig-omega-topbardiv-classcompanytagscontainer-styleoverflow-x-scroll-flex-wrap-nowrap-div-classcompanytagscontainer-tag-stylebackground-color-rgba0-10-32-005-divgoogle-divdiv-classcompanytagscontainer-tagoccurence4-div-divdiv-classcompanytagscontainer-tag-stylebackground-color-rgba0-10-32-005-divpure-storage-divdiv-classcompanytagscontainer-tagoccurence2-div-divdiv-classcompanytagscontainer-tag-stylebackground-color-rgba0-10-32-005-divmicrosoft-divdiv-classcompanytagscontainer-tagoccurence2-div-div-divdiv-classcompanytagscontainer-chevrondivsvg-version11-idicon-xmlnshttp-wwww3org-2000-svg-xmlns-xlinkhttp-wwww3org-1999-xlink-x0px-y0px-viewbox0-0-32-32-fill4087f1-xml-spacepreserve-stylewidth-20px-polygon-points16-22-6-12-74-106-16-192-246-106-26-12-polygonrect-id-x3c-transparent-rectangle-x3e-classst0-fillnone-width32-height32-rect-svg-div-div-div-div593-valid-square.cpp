class Solution {
public:
    int cal(vector<int>& a,vector<int>& b)
    {
        int x1=a[0],y1=a[1];
        int x2=b[0],y2=b[1];
        
        int dx=x1 - x2;
        int dy=y1 - y2;
        return dx*dx + dy*dy;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st;
        st.insert(cal(p1,p2));
        st.insert(cal(p1,p3));
        st.insert(cal(p1,p4));
        st.insert(cal(p2,p3));
        st.insert(cal(p2,p4));
        st.insert(cal(p3,p4));
        
        return st.size()==2 && !st.count(0);
    }
};