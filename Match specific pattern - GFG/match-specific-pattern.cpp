//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}
// } Driver Code Ends


/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       unordered_map<char,int> mp;
       for(auto it:pattern) mp[it]++;
       vector<string> ans;
       for(auto it:dict)
       {
           unordered_map<char,int> a;
           for(auto x:it)
           {
               a[x]++;
           }
           
           if(pattern.size()!=it.size()) continue;
           bool f=true;
           for(int i=0;i<it.size();i++)
           {
               if(mp[pattern[i]]!=a[it[i]]) 
               {
                   f=false;
                   break;
               }
           }
           
           if(f) ans.push_back(it);
       }
       
       return ans;
}