class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int f=0;
        for(int i=1;i<arr.size()-1;i++)
        {
             if(arr[i]<arr[i-1]&&arr[i]<arr[i+1] || arr[i]==arr[i-1])
            return false;
            if(arr[i-1] < arr[i] && arr[i+1] < arr[i]) f++;
            
        }
        if(f==1) return true;
        
        return false;
    }
};