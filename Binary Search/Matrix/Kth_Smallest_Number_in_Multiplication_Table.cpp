

/*
link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

small annoying and key thing to notice is :
while coding binary search portion 
       -> store "ans=mid" in portion where you are doing -> hi = mid-1
       -> if u do opposite of it ie -> lo = mid + 1 -> then many tc's passed but not all
       -> why?
       -> bcz we want 'smallest number' having smaller_elements <=k so we need to optimise by searching for smaller number even if we get a desired answer
    
--- tc ---
42
34
401

*/

class Solution {
public:
    
    int findKthNumber(int m, int n, int k) {
        
        int i,ans=-1;
        
        if(m>n)swap(m,n); //we will iterate through smaller of row and col 
        
        int lo=1, hi=(m*n);
        
        while(lo<=hi){
            
            int mid = lo + (hi-lo)/2;
            int smaller_ele =0;
            
            for(i=1;i<=m;i++){
                smaller_ele += min(n,mid/i);
            }
            
           
            if(smaller_ele <k){
                
                lo = mid+1;
            }
            else{
                
                ans = mid;
                hi = mid-1;
            }
            
            
        }
        
        return ans;
    }
};

