//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        string temp1="";
        int n=str2.length();
        temp1.push_back(str2[n-2]);
        temp1.push_back(str2[n-1]);
        string temp2="";
        temp2.push_back(str1[n-2]);
        temp2.push_back(str1[n-1]);
        for(int i=0;i<n-2;i++)
        {
            temp1+=str2[i];
            temp2+=str1[i];
        }
        // cout<<temp1<<endl;
        // cout<<temp2;
        if(str1==temp1) return true;
        else if(str2==temp2) return true;
        
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends