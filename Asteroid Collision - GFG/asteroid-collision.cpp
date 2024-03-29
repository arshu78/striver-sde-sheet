//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        stack<int> st;
        for(int i=0;i<N;i++)
        {
            if(st.empty() || a[i]>0) st.push(a[i]);
            else 
            {
                while(!st.empty() && st.top()>0 &&  st.top()< -a[i])
                {
                    st.pop();
                }
                
                if(!st.empty() && st.top()== -a[i]) st.pop();
                else if(st.empty() || st.top()<0) st.push(a[i]);
                
            }
        }
        
       vector<int> ans;
        while(!st.empty())
        {
            auto it=st.top();
            st.pop();
            ans.push_back(it);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends