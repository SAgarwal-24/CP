// https://leetcode.com/problems/perfect-squares/

/*
memoization approach was bit different 
- so check it out - https://leetcode.com/problems/perfect-squares/discuss/3824644/
- in memoization - instead of following - take and don't take - standard recursion
- its better to follow - to take all possible - ie take and only take :)

int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }

    int helper(int tar, vector<int>& memo) {
        if (tar == 0) return 0;

        if (memo[tar] != -1) return memo[tar];

        int res = 1e9;
        for (int i = 1; i * i <= tar; ++i) {
            res = min(res, 1 + helper(tar - i * i, memo)); // take all possible squares 
        }

        return memo[tar] = res;
    }

    
*/ 

class Solution {
public:
    
    #define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define watch(x) cout << (#x) << " -> "  << (x) << endl
    
   
    
    int numSquares(int n) {
        
        vector<int>sqs;
        
        for(int i=1; i*i <= n; i++){
            sqs.pb(i*i);
        }
        
        vi dp(n+1, n);
        dp[0] = 0;
        
        for(auto sq: sqs){
            
            for(int num = sq; num <=n; num++){
                
                if(num-sq < 0)
                    continue;
                 
                dp[num] = min(dp[num] , dp[num-sq] + 1);
            }
        }
        
        return dp[n];
 
    }
    
    
};



/*
12
13
1
2
3
4
5
6
7
8
9
15
20
100
1000
10000
999
1000
1001

*/
