//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int f(int i,int arr[])
    {
        if(i==0) return arr[i];
        
        
        int np=0 + f(i-1,arr);
        int pick=INT_MIN;
        if(i>1)
        pick=arr[i] + f(i-2,arr);
        
        return max(pick,np);
    }
    int FindMaxSum(int arr[], int n)
    {
        // vector<int> arr1,arr2;
        
        // for(int i=0;i<n;i++)
        // {
        //     if(i==0)
        //     {
        //         arr2.push_back(arr[i]);
        //     }
        //   else if(i==n-1)
        //   {
        //       arr1.push_back(arr[i]);
        //   }
        //   else
        //   {
        //         arr1.push_back(arr[i]);
        //         arr2.push_back(arr[i]);
        //   }
        // }
        
          vector<int> dp(n+1,-1);
	    
	    dp[0]=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        int np=0 + dp[i-1];
	        int p= arr[i] + dp[i-2];
	        
	        dp[i]=max(p,np);
	    }
	    return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends