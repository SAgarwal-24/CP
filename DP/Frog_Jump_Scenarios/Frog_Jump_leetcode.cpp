
/*

- question : https://leetcode.com/problems/frog-jump/

Time: O(N*N*Log(n))
Space: O(N*N)

- similar ques recommended
 - https://leetcode.com/problems/minimum-sideway-jumps/
 - https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/

implementation is slight tricky , challenge is to maintain index while doing recursive call for next jump

- for each jump (k, k-1, k+1)
- find - next x_coor and check stones exists or not
- if exists - then simply jump to it :)  , and for that u need to find next corrdinate
- for finding next x_corr we can use binary search, or hashing like map 

*/

class Solution {
public:
    
    #define vi vector<int>
    
    int n;
    int memo[2000][2000];
    
    int getIndex(vi &stones, int ind, int nextPos){
        
        int lo = ind + 1,  hi = n-1;
        while(lo <= hi){

            int mid = lo + (hi-lo)/2;

            if(stones[mid] == nextPos){
                return mid;
            }
            
            if(stones[mid] < nextPos){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return -1;
        
    }
    
    bool jump(vi &stones, int ind, int prevJump){ // O(N*N) - bcz N*N calls possible
        
        if(ind == n-1)
            return true;
        
        if(memo[ind][prevJump] != -1){
            return memo[ind][prevJump];
        }
            
        bool isPossible = false;
        
        for(int nextJump=prevJump-1; nextJump<=prevJump+1; nextJump++){ 
            
            if(nextJump==0)
                continue;
            
            int nextPos = stones[ind] + nextJump; 
            
            // check is there stone exists on next position (ie nextPos is present stones array)
            // and if there stone exists (obviously in stone arr) then what is the index of the stone
            
            int nextInd = getIndex(stones, ind, nextPos); // O(log(k))
            
            if(nextInd == -1){
                continue;  // stones not exist with x_coor = nextInd ie water exists at x_coor
            }
            
            if( jump(stones, nextInd, nextJump) ){
                isPossible = true;
                break;
            }
                

        }
        
         return memo[ind][prevJump] = isPossible;
    }
    
    bool canCross(vi & stones) {
        
        
        n = stones.size();
        
        if(stones[1] > 1)
            return false;
        
        
        memset(memo, -1, sizeof(memo));
        
        return jump(stones, 1, 1);
        
    }
    
};

/*



*/
