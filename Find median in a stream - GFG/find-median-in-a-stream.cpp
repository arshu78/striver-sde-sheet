//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
     priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    void insertHeap(int &num)
    {
        if(max_heap.empty() || max_heap.top()>=num)
        {
            max_heap.push(num);
        }
        else
        {
            min_heap.push(num);
        }
         if(max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } 
       
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
         if(max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } 
    }
    
    //Function to return Median.
    double getMedian()
    {
         if(max_heap.size()==min_heap.size())
        {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        else
        {
            return max_heap.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends