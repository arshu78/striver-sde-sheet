//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    long long int l=0,r=len-1;
    
    long long int ans=0;
    
    while(l<r)
    {
        long long int w= r-l;
        long long int h=min(A[l],A[r]);
        ans=max(ans,w*h);
        
        if(A[l]>A[r]) r--;
        else l++;
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends