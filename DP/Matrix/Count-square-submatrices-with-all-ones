//Standard Prefix - Sum of Matrices 
//https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    
    void print(vector<vector<int>>a){
         int i, j, row=a.size(), col=a[0].size();
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
    
    int countSquares(vector<vector<int>>& a) {
        
        int i, j, row=a.size(), col=a[0].size();
        
        vector<vector<int>>ps(row+1,vector<int>(col+1,0));
        
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                ps[i][j] = a[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }
        
        //print(ps);
        
        
        int side = min(row,col), x=0, ans=0;
        
        for(x=1;x<=side;x++){
            
            for(i=1;i<=row-x+1;i++){
                for(j=1;j<=col-x+1;j++){
                    // matrix with top-left corner as (i,j) so all cordinates are
                    // (i,j), (i+x-1,j), (i,j+x-1), (i+x-1,j+x-1)
                    
                    int sum = ps[i+x-1][j+x-1] - ps[i-1][j+x-1] - ps[i+x-1][j-1] + ps[i-1][j-1];
                    
                    if(sum==x*x)ans++;
                }
            }
        }
        
        return ans;
        
    }
};
