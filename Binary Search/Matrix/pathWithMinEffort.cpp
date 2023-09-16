/*

link: https://leetcode.com/problems/path-with-minimum-effort/

If we analyse time complexity properly
 - idea of binary search will hit instantly :)
 - otherwise we will waste time with - backtracking and dfs :(

other way is - dikstra check that too
 - https://leetcode.com/problems/path-with-minimum-effort/discuss/4049576/99.92-oror-Dijkstra's-Algorithm-oror-Binary-Search-oror-Commented-Code

*/

class Solution {
public:
    
    #define vi vector<int>
    #define vvi vector<vi>
    
    int r,c;
    
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int vis[101][101];
    
    bool dfs(int x, int y, int mxDiff, vvi &heights){
        
        if(x==r-1 && y==c-1) // we successfuly reached bottom-right :) with max consecutive height diff as - mxDiff
            return true;
  
        vis[x][y] = 1;
        int val = heights[x][y];
      
        for(int i=0; i<4; i++){
            
            int nx = x+dx[i],  ny = y+dy[i];
            
            if(nx < 0 || ny < 0 || nx == r || ny == c){ // outOfBound conditions
               continue;
            }
            
            int dif = abs(val - heights[nx][ny]);
            
            if( vis[nx][ny] == 0  && dif<=mxDiff && dfs(nx, ny, mxDiff, heights))  { 
               return true;
            }
        
        }
        
       return false;
    
    }
    
    int minimumEffortPath(vvi& heights) {
        
        r = heights.size();
        c = heights[0].size();
        
        
        int lo = 0,  hi = 1e6, ans = 0;
        while( lo <= hi){ // O(nlogn)   -> n = 10^6
            
            int mid = lo + (hi-lo) / 2;
             memset(vis, 0, sizeof(vis));
            
            // dfs function() - time comp : O(r*c) as there are max - r*c calls
            
            if (dfs(0, 0, mid, heights) ){ // if we can reach bottom right with max difference between consecutive cells as 'mid'
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
            
        }
        return ans;
        
    }
};

