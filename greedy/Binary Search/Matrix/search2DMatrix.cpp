// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    
    #define pb push_back
    #define vi vector<int>
    #define vvi vector<vi>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl\
    
    int getNum(int num,vvi &matrix){
        
        int c = matrix[0].size();
    
        int x = num/c , y = num % c;
    
        return matrix[x][y];
    }
    
    bool searchMatrix(vvi& matrix, int target) {
        
        int r = matrix.size(), c = matrix[0].size();
        
        int lo = 0, hi = r*c - 1;
        
        while(lo <= hi){
            
            int mid = lo + (hi-lo)/2;
            
            int num = getNum(mid, matrix);
            
            if(num == target){
                return true;
            }
            else if(num > target) {
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
            
        }
        
        return false;
    }
};
