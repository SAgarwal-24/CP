/*
link: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

target - Maximum Number of Achievable Transfer Requests

1. The most important observation is that the total requests could be at a max of 16
    ( total possibilities - 2^16  could be a possible solution.)
    
2. This is similar to the classic 0/1 knapsack problem, as for each request, 
   we can either take it (1) or not (0).
   
3. Time complexity : (2^M * N) , M = no of reqests, N = no of buildings 
   Space complexity: O(N+M) 

*/

class Solution {
public:
    
    #define vvi vector<vector<int>>
    
    int indegree[21] = {0} ;
    int numOfBuildings = 0;
    int maxAchievableReq = 0;
    
    void dfs(int ind, vvi& requests, int include){
        
        if(ind == requests.size()){
            
            for(int i=0; i<numOfBuildings; i++){ // O(N)
                if (indegree[i] != 0){
                    return;
                }
            }
            
            maxAchievableReq =  max(maxAchievableReq, include);
            
            return;
        }
        
        
        
        dfs(ind +1, requests, include); //skip 
        
        int from = requests[ind][0],  to = requests[ind][1];
        
        indegree[from] --;
        indegree[to] ++;
        
        dfs(ind+1, requests, include +1); // include request[ind+1]
        
        // backtrack
        indegree[from] ++;
        indegree[to] --;
    }
    
    int maximumRequests(int n, vvi& requests) {
        
        this->numOfBuildings = n;
        
        int i, m = requests.size();
        
        dfs(0, requests, 0); // time complexity - 2^m
        
        return maxAchievableReq;
    }
};
