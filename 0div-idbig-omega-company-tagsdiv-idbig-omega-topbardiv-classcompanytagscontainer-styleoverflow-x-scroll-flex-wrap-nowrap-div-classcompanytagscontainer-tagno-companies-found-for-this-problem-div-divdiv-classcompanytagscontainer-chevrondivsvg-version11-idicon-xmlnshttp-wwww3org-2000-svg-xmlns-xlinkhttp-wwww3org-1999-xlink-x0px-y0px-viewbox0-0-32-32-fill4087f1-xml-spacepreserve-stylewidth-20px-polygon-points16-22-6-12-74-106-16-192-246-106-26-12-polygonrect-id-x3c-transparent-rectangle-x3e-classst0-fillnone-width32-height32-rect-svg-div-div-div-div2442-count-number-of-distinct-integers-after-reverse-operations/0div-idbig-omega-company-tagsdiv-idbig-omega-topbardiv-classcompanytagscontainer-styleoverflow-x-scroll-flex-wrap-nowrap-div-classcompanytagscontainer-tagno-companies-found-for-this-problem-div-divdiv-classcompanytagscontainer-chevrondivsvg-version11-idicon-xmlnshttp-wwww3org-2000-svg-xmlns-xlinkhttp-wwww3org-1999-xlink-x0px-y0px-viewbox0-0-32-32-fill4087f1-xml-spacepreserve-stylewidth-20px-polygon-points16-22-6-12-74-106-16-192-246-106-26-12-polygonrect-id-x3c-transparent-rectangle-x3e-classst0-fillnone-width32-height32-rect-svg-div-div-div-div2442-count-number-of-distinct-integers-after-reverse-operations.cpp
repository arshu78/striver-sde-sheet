class Solution {
public:
    int f(int a)
    {
        string s=to_string(a);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        for(auto it:nums)
        {
            st.insert(it);
            int rev=f(it);
            st.insert(rev);
        }
        return st.size();
    }
};