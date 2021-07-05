//https://www.geeksforgeeks.org/dice-throw-dp-30/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    #define ll long long 
    
    ll dp[55][55];
    
    ll fun(int m, int n, int x){
        
        if(x==0 and n==0){
            return 1;
        }
        
        if(n==0)return 0;
        
        if(dp[n][x]!=-1)return dp[n][x];
        
        ll cnt=0;
        
        for(int i=1;i<=m and i<=x;i++){
            cnt+=fun(m,n-1,x-i);
        }
        
        dp[n][x] = cnt ;
        
        return cnt;
        
    }
  
    ll noOfWays(int m , int n , int x) {
        
        memset(dp,-1,sizeof(dp));
        
        return fun(m,n,x);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends
