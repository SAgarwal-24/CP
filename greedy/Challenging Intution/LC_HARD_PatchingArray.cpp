
/*

https://leetcode.com/problems/patching-array/

helpful - https://www.youtube.com/watch?v=K2IomuIFbPg

*/

class Solution {
public:
    int minPatches(vector<int>& a, int n) {
        
        int  patches = 0
            , i=0, si = a.size();
        
        long long int maxReach = 0;
        
        
        
        while(maxReach < n){
            
             if (i<si && maxReach >= a[i]-1){
            // no need to patch in this case 
                 maxReach += a[i];
                 i++;
            // we can successfully generate numbers from  [1 to maxReach] without losing any number in b/w
            }
            else{ // maxReach < a[i] - 1
                // we need to patch - since we can loose some numbers b/w [maxReach to a[i]] or [maxReach to n]
                
                patches += 1;
                maxReach += maxReach + 1;
            }
            
            
            
            
        }
        
        
        return patches;
        
    }
};

/*







Input set        set of numbers we can generate from input set
1                   1

1 2                 1 2  3


1 2 3              1 2 3 4 5



1 2 5             1 2 3 5 6 7 8 (4 missing)

1 2 4 5           1 2 3 4 5 6 7 8 9 10 11 12
sum = 12


1 2 2 2           1 2 3 4 5 6 7 
sum = 7


1 2 2 2 3        1 2 3 4 5 6 7 8  9 10
sum = 10

1 2 2 2 7        1 2 3 4 5 6 7 8 9 10 11 12 13 14
sum = 14


1      (n=20)   1 2 4 8 

------------- more understanding code snippet -------------

 while(maxReach < n){
            
            if(i<si && maxReach + 1 == a[i]){
                // no need to patch in this case 
                 maxReach += a[i];
                 i++;
                // we can successfully generate numbers from  [1 to maxReach]
               
            }
            else if (i<si && maxReach >= a[i]){
            // no need to patch in this case 
                 maxReach += a[i];
                 i++;
            // we can successfully generate numbers from  [1 to maxReach]
            }
            else{ // maxReach < a[i] - 1
                // we need to patch - since we can loose some numbers b/w [maxReach to a[i]] or [maxReach to n]
                
                patches += 1;
                maxReach += maxReach + 1;
            }
            
            
            
            
        }


*/
