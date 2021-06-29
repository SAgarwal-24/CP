/*
Largest Divisible Subset
https://leetcode.com/problems/largest-divisible-subset/
--------
Simple lis - instead of a[i]<a[j] condition is a[i]%a[j]==0 and also print the subsequence

*/

class Solution {
public:
    
    #define all(c) c.begin(),c.end()
    
    vector<int> largestDivisibleSubset(vector<int>& a) {
        
        int i,j,n=a.size(),mx=-1,ind=0;
        sort(all(a));
       
        int dp[1005]={0};
        int lis[1005];
        
        memset(lis,-1,sizeof(lis));
        
        
        for(i=1;i<n;i++){
            
            for(j=0;j<i;j++){
                
                if(a[i]%a[j]==0 and dp[j]+1>=dp[i]){
                    
                    dp[i] = dp[j]+1;
                    lis[i] = j;
                }
                
            }
            
            if(mx<dp[i]){
                mx=dp[i];
                ind=i;
            }
        }
        
      /*  
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
        for(i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        
        for(i=0;i<n;i++){
            cout<<lis[i]<<" ";
        }
        cout<<endl;
        */
        
        
        vector<int>ans;
       
        
      //  cout<<mx<<" "<<ind<<endl;
        
        int g=0;
        while(1){
            ans.push_back(a[ind]);
            ind=lis[ind];
       
            if(ind==-1)break;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

/*
[1,2,3,4,6,8,9,12,15,18,21,24,27]
[1,2,7,14,28,56]
[1,2,7,49,343,2401]
*/
