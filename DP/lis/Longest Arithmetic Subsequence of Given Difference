// link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference
// simple straight forward logic 




class Solution {
public:
    
        
    #define pb push_back
    #define vi vector<int>
    #define vvi vector<vi>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    int longestSubsequence(vi& a, int dif) {
        
        int ans = 1;
        unordered_map<int, int> dp;

   // dp[ele] = max len of subsequence ending with element 
        
        for(auto ele : a){
            
     dp[ele] =  ( dp.find(ele - dif) != dp.end() )            
                ? max(dp[ele], 1 + dp[ele-dif] )
                : 1;
            
            ans = max(ans, dp[ele]);
        }
        
        
        return ans;
    }
};
