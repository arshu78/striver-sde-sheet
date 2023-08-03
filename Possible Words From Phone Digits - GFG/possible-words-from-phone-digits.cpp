//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int ind,int a[],int n,string out,string mp[],vector<string>& ans)
    {
        if(ind>=n) 
        {
            ans.push_back(out);
            return;
        }
        
        string val=mp[a[ind]];
        for(int i=0;i<val.size();i++)
        {
            out.push_back(val[i]);
            solve(ind+1,a,n,out,mp,ans);
            out.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        if(N==0) return ans;
        string out;
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int i=0;
        solve(i,a,N,out,mp,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends