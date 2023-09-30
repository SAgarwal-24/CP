/*

link - https://leetcode.com/problems/peak-index-in-a-mountain-array/
https://leetcode.com/problems/peak-index-in-a-mountain-array/discuss/3815723/Binary-Search-or-C%2B%2B-or-corner-cases-handled

other useful solution - https://leetcode.com/problems/peak-index-in-a-mountain-array/discuss/1017868/C%2B%2B-O(n)-O(log(n))-Simple-and-Short-Solutions-detailed-explanations


int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid+1])         
                low = mid+1;    // if we are on left side of peak -> decrease window size (lo = mid +1)-> and move to right side 
            else
                high = mid-1; // if we are on right side of peak -> decrease window size (hi = mid-1) -> and move to left side 
        }
        return low;
    }

    

*/ 

class Solution {
public:
    
    int getIndex(vector<int>& a, int ind){ // ind -> possible index
        
        int n = a.size();
        
        for(int i=ind-1; i<=ind+1; i++){   // check all 3 possiblities of index ie [ind-1, ind, ind +1]
            
            if(0<=i && i<=n-1 && 0<=i-1 && i+1<=n-1){
            
                if(a[i-1]<a[i] && a[i]>a[i+1])
                    return i;
            }
        }
        
        return -1;
    }
    
    int peakIndexInMountainArray(vector<int>& a) {
        
        int n = a.size();
        int lo = 0, hi = n-1;
        
        while(lo <= hi){
            
        
            int mid = lo + (hi-lo)/2;
            
            int possibleIndex = getIndex(a, mid);
            
            if( possibleIndex != -1 ){
                return possibleIndex;
            }
            else if(0<=mid-1 && a[mid-1] < a[mid]){
                lo = mid + 1;
            }
            else{
                hi = mid -1;
            }
        }
        
        return -1;
    }
};

/*


[0,1,0]
[0,2,1,0]
[0,10,5,2]
[1,12,3]
[1,2,3,4,3,2,1]
[1,2,10,2,1]
[1,2,3,4,5,6,7,8,9,8]
[3,5,3,2,0] (corner case)
*/
