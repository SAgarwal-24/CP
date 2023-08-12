/*

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

- all numbers are unique
- just need to find pivot

*/

class Solution {
public:
    
    #define pb push_back
    #define vi vector<int>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    int findMin(vi& a) {
        
        int n = a.size();
        
        if(a[0] <= a[n-1])  // all sorted cases handled
            return a[0];
        
        
        int lo = 0, hi = n-1;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            
            if(a[mid] > a[mid+1]){ // mid+1 <= n-1 (for all rotated cases - so no chance of out of bound exception)
                return a[mid+1];
            }
            
            if(a[0] <= a[mid])
                lo = mid +1;
            else
                hi = mid-1;
        }
        
        return -1;
    }
};

