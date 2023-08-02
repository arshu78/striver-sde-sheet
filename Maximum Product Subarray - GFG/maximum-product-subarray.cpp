//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	   long long mx=arr[0],mn=arr[0];
	   
	   long long ans=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	        {
	            swap(mn,mx);
	        }
	        mn=min((long long)arr[i],arr[i]*mn);
	        mx=max((long long)arr[i],arr[i]*mx);
	        
	        ans=max(ans,mx);
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
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends