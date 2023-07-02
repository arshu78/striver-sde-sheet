//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
         s+=".";
    
    string w="";
    
    string str="";     // ans string 
    
    for(int i=0;i<s.size();i++){
	
        if(s[i]!='.'){
            w+=s[i];
        }
		
        else if(s[i]=='.' &&  w.size()>0){
            reverse(w.begin(),w.end());
            string temp=w+".";
            str+=temp;
            w="";
        }
    }
    
	
    str.pop_back();
	
    reverse(str.begin(),str.end());
    
    return str;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends