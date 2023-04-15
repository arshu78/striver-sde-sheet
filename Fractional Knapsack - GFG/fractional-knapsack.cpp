//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item a,Item b)
    {
        double i=(double)a.value / (double) a.weight;
        double j=(double)b.value / (double) b.weight;
        
        return i > j;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        
        int cur=0;
        double find=0.0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight + cur <=W)
            {
                cur+=arr[i].weight;
                find+=arr[i].value;
                
            }
            else
            {
                int remain= W - cur;
                find+=  arr[i].value / (double)arr[i].weight * (double) remain;
                break;
            }
        }
        return find;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends