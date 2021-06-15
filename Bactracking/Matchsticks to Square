/*
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3780/
Matchsticks to Square
--------
helpful editorial : https://leetcode.com/problems/matchsticks-to-square/discuss/1273952/C%2B%2B-or-Recursion-with-Various-Optimization-or-Everything-You-Need-to-Know-or-Explained
------

Most important step bcz of it passes TLE 
 as bigger nos are considered first so useless processing decreases incredible
        sort(a.begin(),a.end(),greater<int>());
------------
*/

class Solution {
public:
    
    int sum=0;
    
    bool dfs(vector<int>& a,int sub[],int ind,int n){
         
         if(ind==n){
            
             for(int i=0;i<4;i++){
                 if(sum!=sub[i])return false;
             }
             
             return true;
         }
        
        for(int i=0;i<4;i++){
    
            if(sub[i]+a[ind]<=sum){
                
                sub[i]+=a[ind];
                
                bool ok=dfs(a,sub,ind+1,n);
                if(ok)return true;
                
                sub[i]-=a[ind]; 
            }
            
        }
        
        return false;
           
    }
    
    bool makesquare(vector<int>& a) {
        
        // Most important step bcz of it passes TLE 
        // as bigger nos are considered first so useless processing decreases incredible
        sort(a.begin(),a.end(),greater<int>());
        
        int i,j,k,l, n=a.size();
        

        int sum=0;
        for(i=0;i<n;i++){
            sum+=a[i];
        }
        
        if(sum%4!=0)return false;
        
        this->sum=sum/4;
        
        int sub[4]={0}; //4-subsets storing sum of 4 sides
        
        return dfs(a,sub,0,n);
        
    }
};
/*
[1,1,2,2,2]
[3,3,3,3,4]
[1,34,55]
[5,3,5,6]
[1,1,1,1,1]
[3,4,2,1]
[12,12,12,16,20,24,28,32,36,40,44,48,52,56,60]
[5,5,5,5,4,4,4,4,3,3,3,3]
*/
