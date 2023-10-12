/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int searchl(MountainArray& a,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=(low + high) >>1;
            if(a.get(mid)==target) return mid;
            else if(a.get(mid)<target) low=mid+1;
            else high=mid-1;
        }
        
        return -1;
    }
    int searchr(MountainArray& a,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=(low + high) >>1;
            if(a.get(mid)==target) return mid;
            else if(a.get(mid)>target) low=mid+1;
            else high=mid-1;
        }
        
        return -1;
    }
    int f(MountainArray& a,int n)
    {
        int l=0,h=n-1;
        
        while(l<h)
        {
            int mid=(l+h) >> 1;
            
            if(a.get(mid)<=a.get(mid+1))
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }
        }
        
        return l;
    }
    int findInMountainArray(int target, MountainArray &ans) {
        
       int n=ans.length();
        int peak=f(ans,n);
        
      
                int s1=searchl(ans,0,peak-1,target);
           
            
                int s2=searchr(ans,peak,ans.length()-1,target);
            
                if(s1==-1) return s2;
                else return s1;
        
        return -1;
    }
};