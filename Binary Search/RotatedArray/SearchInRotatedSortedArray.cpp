/*
https://leetcode.com/problems/search-in-rotated-sorted-array/


helpful - https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14436/Revised-Binary-Search

1. one approach is find pivot and then search sepreately - https://leetcode.com/submissions/detail/756039042/

2. and other approach(below) is without finding pivot

*/

class Solution {
public:
    
    #define pb push_back
    #define vi vector<int>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    int search(vi& a, int target) {
        
        int n = a.size();
        
        int lo = 0,  hi = n-1;
        
        while(lo <= hi ){
            
            int mid = lo + (hi-lo)/2;
            
            if( a[mid] == target)
                return mid;
            
            if(a[lo] <= a[mid]){ // range -> [lo, mid] is properly sorted (standard scenario)
                
                if(a[lo] <= target &&  target < a[mid]){ // just like standard binary search scenario - no rotation in array 
                    hi = mid - 1;
                }
                else{ 
                    lo = mid + 1;
                }
                
            }
            else{
                
                if(a[mid]<target && target <=a[hi]){ // range -> [mid+1, target] is properly sorted (standard scenario) -  - no rotation in array 
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
