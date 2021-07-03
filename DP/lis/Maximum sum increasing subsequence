#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    int dp[n+1]={0};
	    
	    int i,j, ans=0;
	    
	    for(i=0;i<n;i++){
	        dp[i]=a[i];
	    }
	    
	    ans=dp[0];
	    
	    for(i=1;i<n;i++){
	        
	        for(j=0;j<i;j++){
	            if(a[j]<a[i] and dp[j]+a[i]>dp[i]){
	                dp[i] = dp[j] + a[i];
	            }
	        }
	        
	        ans=max(ans,dp[i]);
	    }
	    
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
