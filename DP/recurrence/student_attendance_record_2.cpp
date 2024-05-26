/*


https://leetcode.com/problems/student-attendance-record-ii/


T(n) is the total number of all possible attendance records with length n.
P(n) is the total number of all possible attendance records ended with 'P' with length n.
L(n) is the total number of all possible attendance records ended with 'L' with length n.
A(n) is the total number of all possible attendance records ended with 'A' with length n.

T(n) = A(n) + P(n) + L(n), n ≥ 1

Reusability ->   say n = 10
and after 2 records 
  
      student-1    student-2
n=10     P           L
n=9      L           P

on n = 8 onwards both have same - no of total valid ways  ie order - 'PL' and 'LP'  won't make any difference
as our rec. tree will be same

time : O(n)
space : O(n*3*2) = O(n)

*/



class Solution {
public:
    
    int memo[100001][4][4];
    
    int mod = 1e9 + 7;
    
    int rec(int n, int a, int l){
        
        if(a >= 2){
            return 0;
        }
        
        
        if(n == 0){
            return 1;
        }
        
        if(memo[n][a][l] != -1){
            return memo[n][a][l];
        }
        
    
        int op1 = 0, op2 = 0, op3 = 0;
        
        op1 = rec(n-1, a+1, 0); // a
        
        if(l <= 1){
           op2 = rec(n-1, a,   l+1); // l
        }
        
        op3 = rec(n-1, a,   0); // p
        
        
        return memo[n][a][l] = ((op1 + op2) % mod + op3) %mod;
    }
    
    int checkRecord(int n) {
        
        memset(memo, -1, sizeof(memo));
        
        return rec(n, 0, 0);
    }
};

/*


  2


PPPP

PPPPL
PPPPA
PPPPP




*/
