
/*

link: https://leetcode.com/problems/interleaving-string/


Helpful resource : checkout O(n) solution (bottom up)
https://leetcode.com/problems/interleaving-string/discuss/3956393/99.78-2-Approaches-DP-and-Recursion

Space optimized idea: 
  Approach: 1D Dynamic Programming
  The optimization from 2D to 1D DP is based on the observation that the state of dp[i][j] in the 2D DP array depends only on dp[i-1][j] and dp[i][j-1]. 
  Therefore, while iterating through the strings, the current state only depends on the states in the previous row of the 2D DP array, 
  which means we can optimize our space complexity by just keeping track of one row (1D DP).

Recurrence
 
memo[x][y] = represent whether substring s3[x][y] can be formed by interleaving s1[x] and s2[y] 

f(x, y) =  f(x+1, y) ,  s1[x] == s3[x+y]
           f(x, y+1) ,  s2[y] == s3[x+y]
           0            s1[x] != s3[x+y] or s2[y] != s3[x+y]
           0            x>n1 || y>n2 
           1            x==n1 && y==n2 && x+y==s3.size();
           
LCS Recurrence

f(x, y) =  1 + f(x+1, y+1)                , s1[x] == s2[y]
           max(f(x+1, y), f(x, y+1))      , s1[x] != s2[y]
           0                              , x==s1.size() || y==s2.size()


Time : O(n * m)
Space : O(n*m) + O(n+m) (auxillary stack space) 

*/


class Solution {
public:
    
     int n1 , n2 ;
    
     int memo[101][101];
    
     bool helper(string &s1, string &s2, string &s3, int x,  int y){
         
         
         if(x>n1 || y>n2 ){
             return 0;
         }
         
         if(x==n1 && y==n2){
             return (x+y)==s3.size();
         }
         
         if(memo[x][y] != -1){
             return memo[x][y] == 1;
         }
         
         int op1 = 0, op2 = 0;
         
         op1 = (s1[x] == s3[x+y]) ? helper(s1, s2, s3, x+1, y) : 0;
         op2 = (s2[y] == s3[x+y]) ? helper(s1, s2, s3, x, y+1) : 0;
         
         return  memo[x][y] = (op1 == 1  || op2 == 1)  ;
     }
         
    
    bool isInterleave(string s1, string s2, string s3) {
        
         n1 = s1.size(), n2 = s2.size();
        
        memset(memo, -1, sizeof(memo));
        
         return helper(s1, s2, s3, 0, 0);
    }
};

