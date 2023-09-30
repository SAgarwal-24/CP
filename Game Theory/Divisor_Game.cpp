/*
https://leetcode.com/problems/divisor-game/
------
concept of win(n) -> calling -> !win(n-x) 

*/

class Solution {
public:
    
    int dp[1005];
    
    bool win(int n){
        
        if(n==1)return 0;
        
        if(dp[n]!=-1)return dp[n];
        
        int outcome=0;
        
        for(int x=1;x<n;x++){
            
            if(n%x==0 and outcome==0){
                outcome = !win(n-x);
            }
        }
        
        dp[n]=outcome;
        
        return outcome;
    }
    
    bool divisorGame(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        int ans=win(n);
        
        // for(int i=0;i<=12;i++){
        //     cout<<dp[i]<<" ";
        // }
        
        return ans;
    }
};
/*
2
3
4
5
6
7
100
300
*/
