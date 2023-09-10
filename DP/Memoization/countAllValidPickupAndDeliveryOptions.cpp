/*

time : O(n^2)
space : O(n^2) + O(n+n)

*/

class Solution {
public:
    
    int mod = 1e9 + 7;
    int memo[501][501];
    
    int cnt(int p,  int d){
        
        if(p==0 and d==0)
            return 1;
        
        if(p<0 || d<0)
            return 0;
        
        if(memo[p][d] != -1)
            return memo[p][d];
        
        int op1 = 0, op2 = 0;
        
        op1 = cnt(p-1, d);  // total count when  chosen one of the available 'p' pickup options
        
        if(p<d)
        op2 = cnt(p, d-1);  // total count chosen one of the available 'd-p' delivery options
        
        
        return memo[p][d] = ((p*1LL*op1) % mod  + (d-p)*1LL*op2 % mod)%mod;
    }
    
    int countOrders(int n) {
    
       memset(memo, -1, sizeof(memo));
       return cnt(n, n);
    }
};
