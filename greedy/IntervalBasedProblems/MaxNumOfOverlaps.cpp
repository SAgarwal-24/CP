/*

- https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

- minmumNumberOfGroups / MaxNumOfOverlaps
- Intuition: Actually we need to find - 'Maximum no. of overlaps'
- difference array technique

*/

class Solution {
public:
    
    #define vi vector<int>
    #define vvi vector<vi>
    
    int minGroups(vvi& intervals) {
        
        int maxNumOfOverlaps = 0, n = intervals.size(), mxRi = -1;
        
        int diffArray[1000005] = {0};
        
        
        for(int i=0; i<n; i++){
            
            int left = intervals[i][0];
            int ri = intervals[i][1];
            
            mxRi = max(mxRi, ri);
            
            diffArray[left] += 1;
            diffArray[ri+1] -= 1; 
            
        }
        
        int overLaps = 0;
        for(int i=0; i<=mxRi; i++){
            overLaps += diffArray[i];
            maxNumOfOverlaps = max(maxNumOfOverlaps, overLaps);
        }
        
        return maxNumOfOverlaps;
        
    }
};
