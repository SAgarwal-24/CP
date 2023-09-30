/*
Better Solution is using dp or stack(histogram based app) (https://leetcode.com/problems/maximal-rectangle/discuss/764461/c%2B%2B-dp)
- similar to finding : Largest Rectangle in Histogram(https://leetcode.com/problems/largest-rectangle-in-histogram/)
- but can be solved using prefix sum on matrix + binary search which I did see below 

https://leetcode.com/problems/maximal-rectangle/
-------------------------------
let row=col=200=n (worst case)

Then
Time complexity
O(n^3 log(n))
space: O(n^2)

Monotonicity for binary search

since -> area = length * breadth  .....(1)
  
  for all values of length we can apply binary search on breadth bcz 
  in (1) 
   say a1 = l1 * b1 and
        a2  = l1 * b2  
		so if b1>b2 then a1>a2
    
 */

class Solution {
public:
    
    bool check(vector<vector<int>>& pre, int row,int col,int len, int bre){
      
        int i, j;
        
        for(i=1;i<=row-len+1;i++){
            for(j=1;j<=col-bre+1;j++){
                
                int x=i+len-1, y=j+bre-1;
                
                if(pre[x][y]-pre[x][j-1]-pre[i-1][y]+pre[i-1][j-1] == len*bre){
                    
                    return true;
                }
                    
            }
        }
        
        return false;
    }
    
    void print(vector<vector<int>>& a,int row,int col){
        
        int i, j;
        
         for(i=0;i<=row;i++){
            for(j=0;j<=col;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
    
    int maximalRectangle(vector<vector<char>>& a) {
        
        int i, j, row=a.size();
        if(row==0)return 0;
        
        int col=a[0].size();
        if(col==0)return 0;
        
        vector<vector<int>>prefix(205,vector<int>(205,0));
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                prefix[i+1][j+1]=a[i][j]-'0';
            }
        }
        
       // print(prefix,row,col);
        
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                prefix[i][j]+=prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
      //  print(prefix,row,col);
        
    
        
        int  lo=1, hi=col,ans=0;
        
    
        //checking all rows
        for(i=1;i<=row;i++){
            
            int m1 = i;
            lo=1, hi=col;
            
			//binary search on column
            while(lo<=hi){
                int m2= lo + (hi-lo)/2;
                
               
                if(check(prefix,row,col,m1,m2)){
                    
                    ans=max(ans,m1*m2);
                    lo=m2+1;
                 }
                else{
                    hi=m2-1;
                }
                
            }
        
        }
        
        
        return ans;
    }
};
/* ----tcs ----
[["1","0","0","0","1"],["1","1","0","1","1"],["1","1","1","1","1"]]
[["0"],["1"],["0"]]
[["0"],["1"],["0"],["0"],["1"],["0"]]
[["1"],["1"],["1"],["1"],["1"],["0"]]
[["0","1"],["0","1"],["0","1"],["0","1"],["0","1"],["0","1"]]
[["0","1"],["1","1"],["1","1"],["1","1"],["0","1"],["0","1"]]
*/
