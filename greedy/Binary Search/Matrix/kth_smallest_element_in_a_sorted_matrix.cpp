/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
-----
helpful resource: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85173/Share-my-thoughts-and-Clean-Java-Code
----------


*/

class Solution {
public:
    
    #define all(x) x.begin(), x.end()
    
    int kthSmallest(vector<vector<int>>& a, int k) {
        
        int ans=0,i,j,row,col,lo,hi,n=a.size();
        
        lo=a[0][0], hi=a[n-1][n-1];
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            int cnt=0;
            
            for(row=0;row<n;row++){
                cnt+=upper_bound(all(a[row]),mid)-a[row].begin();
            }
            
            if(cnt>=k){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        
        return ans;
        
    }
};
