//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       if(s1=="0" || s2=="0") return "0";
       
       int m=0,n=0;
       while(m<s1.size() && s1[m]=='0') m++;
       if(m==s1.size()) return "0";
       
        while(n<s2.size() && s2[n]=='0') n++;
       if(n==s2.size()) return "0";
       
       
       int sign=0;
       int x=0,y=0;
       
       if(s1[0]=='-')
       {
           sign++;
           x=1;
       }
       if(s2[0]=='-')
       {
           sign++;
           y=1;
       }
       
       
       vector<int> ans(s1.size() + s2.size(),0);
       string res="";
       for(int i=s1.size()-1;i>=x;i--)
       {
           for(int j=s2.size()-1;j>=y;j--)
           {
                ans[i+j+1]+= (s1[i] - '0') * (s2[j] - '0');
                ans[i+j] += (ans[i+j+1]) / 10;
                ans[i+j+1] = ans[i+j+1] % 10;
           }
       }
       
       int k=0;
       while(k<ans.size() && ans[k]==0) k++;
       
       while(k<ans.size()) res+=(ans[k++] + '0');
       
       if(sign==1)
       return "-"+res;
       
       return res;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends