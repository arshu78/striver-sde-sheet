//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int lmin[n],rmax[n];
        
        lmin[0]=arr[0];
        rmax[n-1]=arr[n-1];
        
        //calculating minimum from left side
        
        for(int i=1;i<n;i++)
        {
            lmin[i]=min(lmin[i-1],arr[i]);
        }
        
        //calculating for right side
        
        for(int i=n-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],arr[i]);
        }
        
        //storing the answer
        
        int i=0,j=0,ans=-1;
        
        while(i<n && j<n)
        {
            if(lmin[i]<=rmax[j]) // check for less than rmax[j] 
            {
                ans=max(ans,j-i); 
                j++; // here we know the greater element is always on right ot rmax
            }
            else
            {
                i++; // beacause the minimum element always on right of lmax;
            }
        }
        
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends