//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    map<char,int> mp;
    string ans="";
    int mini=INT_MAX;
    for(int i=0;i<s.length();i++)
    {
        if(mp.find(s[i])!=mp.end())
        {
            mini=i;
            break;
        }
        else
        {
            mp[s[i]]=i;
        }
    }
    
    if(mini==INT_MAX) return "-1";
    ans.push_back(s[mini]);
    return ans;
}