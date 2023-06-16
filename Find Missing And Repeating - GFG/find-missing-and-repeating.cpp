//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            mp[i]=0;;
        }
        for(auto it:arr) mp[it]++;
        int r,m;
        for(auto it:mp)
        {
            if(it.second>1) r=it.first;
            if(it.second==0) m=it.first;
        }
        return{r,m};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends