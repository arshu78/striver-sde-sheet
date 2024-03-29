//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPlace(vector<int>& a,int n,int mid,int k)
    {
        int cnt=1,last=a[0];
        
        for(int i=1;i<n;i++)
        {
            if(a[i] - last >=mid)
            {
                cnt++;
                last=a[i];
            }
        }
        
        return cnt>=k;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        
        int low=1,high=stalls[n-1] - stalls[0];
        
        int ans=0;
        
        while(low<=high)
        {
            int mid=(low + high) >>1;
            
            if(isPlace(stalls,n,mid,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends