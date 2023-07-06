class Solution {
public:
bool checker(vector<int>&arr,int k,int mid){
        int sum=0;
        for(int i=0;i<mid;i++)sum+=arr[i];
        int l=0,r=mid;
        int maxi=sum;
        while(r<arr.size()){
            sum-=arr[l++];
            sum+=arr[r++];
            maxi=max(sum,maxi);
        }
        return maxi>=k;
    }
    int minSubArrayLen(int k, vector<int>& arr) {
          int n=arr.size();
         int low=1,high= n;
         int ans=0;
         while(low<=high){
            int mid=low+(high-low)/2;
            if(checker(arr,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
         }
         return ans;
       

    }
};