//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        for(int i=0;i<arr.size();i++)
        {
            if(i==0 || arr[i]!=arr[i-1])
            {
                for(int j=i+1;j<arr.size();j++)
            {
                
                if(j==i+1 || arr[j]!=arr[j-1])
                {
                    int start=j+1,end=arr.size()-1;
                
                while(start<end)
                {
                    long long sum=arr[i] + arr[j] + arr[start] + arr[end];
                    if(sum==k)
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[start]);
                        temp.push_back(arr[end]);
                        
                        st.insert(temp);
                        
                        start++;
                        end--;
                    }
                    else if(sum<k)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
                
                
                }
                
                
            }
            }
            
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends