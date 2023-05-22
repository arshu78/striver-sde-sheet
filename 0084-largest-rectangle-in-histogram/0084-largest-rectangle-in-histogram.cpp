class Solution {
public:
    vector<int> pgs(vector<int> nums)
    {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 && nums[st.top()]>=nums[i]) st.pop();
            
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> ngs(vector<int> nums)
    {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1 && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> l=pgs(heights);
        vector<int> r=ngs(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            if(r[i]!=-1)
            maxi=max(maxi,heights[i]*(r[i]-l[i]-1));
            else
            {
                 maxi=max(maxi,heights[i]*(n-l[i]-1));
            }
        }
        return maxi;
    }
};