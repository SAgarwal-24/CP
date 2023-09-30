/*

https://leetcode.com/problems/count-all-possible-routes/

-> it looks tough and doesn't give intution of memoization on first look (bcz we the valid paths seems as cycle) but its a simple memoization and easy problem

*/

class Solution {
public:
    
    #define vi vector<int>
    
    int dp[101][201];
    int mod = 1e9 + 7;
    
    int dfs(vi& locations, int start, int finish, int fuel){
        
        if(fuel < 0){
            return 0;
        }
        
        if(dp[start][fuel] != -1){
            return dp[start][fuel];
        }
        
        int cnt = 0;
        
        if(start == finish){
            cnt += 1;
        }
        
    
        for(int ind=0; ind<locations.size(); ind++){
            
            if(ind != start){
                
               int usage = abs( locations[start] - locations[ind] ); 
                
               cnt = (cnt + dfs(locations, ind, finish, fuel - usage)) % mod;
                
            }
        }
        
        return dp[start][fuel] = cnt;
    }
    
    int countRoutes(vi& locations, int start, int finish, int fuel) {
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(locations, start, finish, fuel);
    }
};

/*
[1,2,3]
0
2
40

*/
