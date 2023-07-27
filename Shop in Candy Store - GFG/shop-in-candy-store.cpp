//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
        sort(candies,candies+n);
        
        int mn=0,mx=0,k=K;
        
        int i=0,j=n-1;
        while(i<=j)
        {
            mn+=candies[i++];
            j-=k;
        }
        k=K;
        
        i=0,j=n-1;
         while(i<=j)
        {
            mx+=candies[j--];
            i+=k;
        }
        
        return {mn,mx};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends