//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int z=0,o=0,ans=-1;
        
        for(auto it:str)
        {
            if(it=='0')
            {
                z++;
            }
            if(it=='1')
            {
                o++;
            }
            
            if(z==o)
            {
                ans++;
                z=0;
                o=0;
            }
        }
        if(ans==-1 || z!=0 || o!=0) return -1;
        return ans+1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends