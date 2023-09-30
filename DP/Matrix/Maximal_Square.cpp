// https://leetcode.com/problems/maximal-square/
// Space : O(1)
// Time  : O(m*n)


class Solution {
public:
    
    void print(vector<vector<char>>a){
         int i, j, row=a.size(), col=a[0].size();
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        
        int i,j,row=mat.size(),col=mat[0].size(),ans=0;
        
        vector<vector<int>>a(row,vector<int>(col,0));
        
         for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                a[i][j] = mat[i][j] - '0';
        
       
        
        //We need square with all ones
        //So if any cell is '0' then this cell won't contribute to answer
        //otherwise we have to follow notion of prefix sum 
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                
                if(i>0 and j>0 and a[i][j]==1)
                    a[i][j] = min(a[i-1][j],min(a[i][j-1], a[i-1][j-1]))+1;
                
                if(ans<a[i][j])
                    ans = a[i][j];
                
            
            }
        }
        
        
     //  print(a);
        
       
        return ans*ans;
        
    }
};
/*
[["1","1","1"],["1","1","1"],["1","1","1"]]
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
[["0","1"],["1","0"]]
[["0"]]
[["1"]]
[["0","1"],["1","1"],["1","1"],["1","1"],["1","0"],["1","0"],["1","0"]]
[["1","1","1","0","0"],["1","1","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

*/
