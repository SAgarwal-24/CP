
/*
https://leetcode.com/problems/unique-paths-ii/

- some other useful solutions
https://leetcode.com/problems/unique-paths-ii/discuss/23248/My-C%2B%2B-Dp-solution-very-simple!
https://leetcode.com/problems/unique-paths-ii/discuss/23252/4ms-O(n)-DP-Solution-in-C%2B%2B-with-Explanations

(see space optimization post)
https://leetcode.com/problems/unique-paths-ii/discuss/3897923/Simple-Solution-with-explanation-From-Top-Down-to-Bottom-Up!

----------
Time - O(rows*cols)

space - O(rows*cols) + O(rows+cols)     (memoization - auxillary stack space is O(rows+cols) )
      - O(rows*cols)                    (bottom approach)
*/

class Solution {
public:
    
    #define pb push_back
    #define vi vector<int>
    #define vvi vector<vi>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    int rows, cols;
    int memo[101][101];
    
    int dfs(vvi&  obstacleGrid, int x, int y){
        
        if(x>=rows || y>=cols || obstacleGrid[x][y]==1)
            return 0;
        
        if(x==rows-1 && y==cols-1)
            return 1;
        
        if(memo[x][y] != -1)
            return memo[x][y];
        
        return  memo[x][y] = dfs(obstacleGrid, x, y+1) +  dfs(obstacleGrid, x+1, y);
    }
    
    int uniquePathsWithObstacles(vvi& obstacleGrid) {
        
        this->rows = obstacleGrid.size();
        this->cols = obstacleGrid[0].size();
        memset(memo, -1, sizeof(memo)); // memset - Sets the first num bytes- of the block of memory pointed by ptr (memo[][] 2d array) to the specified value
        
        return dfs(obstacleGrid, 0, 0);

       // return bottomUp(obstacleGrid);
    }

  int bottomUp(vvi &obstacleGrid){
        
        vvl dp(rows+1, vl(cols+1));
        
        for(int x=rows-1; x>=0; x--){
            for(int y=cols-1; y>=0; y--){
                
                if(obstacleGrid[x][y] == 1){
                    dp[x][y] = 0;
                    continue;
                }
                
                if(x==rows-1 && y==cols-1){
                    dp[x][y] = 1;
                }
                else{
                    
                    ll right = 0, down = 0;
                    
                    right =  (y+1<cols) ? dp[x][y+1] : 0;
                    down  =  (x+1<rows) ? dp[x+1][y] : 0;
                    
                   dp[x][y] = right + down; 
                }
                   
            }
        }
        
        return dp[0][0];
    }
};

