//link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
public:
    
    #define vi vector<int>
    #define vvi vector<vi>
    
    int rows=0, cols=0, mod = 1e9+7;
   
    int dp[1001][1001]; 
     
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    bool check(int x, int y){
      return (x>=0 && y>=0 && x<rows && y<cols);
    }
    
    int dfs(vvi& grid,int x,int y){
        
      
        int cnt=1;
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        for(int i=0; i<=3; i++){      
            
            int x_ = x + dx[i],  y_ = y + dy[i];
            
            if( check(x_, y_) and  grid[x][y] < grid[x_][y_]){
                cnt = (cnt + dfs(grid, x_, y_)) % mod;
            }
        }
        
        return dp[x][y] = cnt;
    }
    
    int countPaths(vvi& grid) {
        
        memset(dp, -1, sizeof(dp));
        int increasingPaths=0;
        
        rows = grid.size(),  cols = grid[0].size();
        
         for(int x=0; x<rows; x++){
            for(int y=0; y<cols; y++){              
                increasingPaths = (increasingPaths + dfs(grid,x,y))%mod;     
            }    
        }
        
        return increasingPaths;
    }
};


