class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int i=1;
        int sum=0;
        while(st.size()!=n)
        {
            if(st.find(k-i)==st.end())
            {
                sum+=i;
                st.insert(i);
            }
            i++;
        }
        
        return sum;
    }
};