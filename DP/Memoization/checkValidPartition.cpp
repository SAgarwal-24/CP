// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

/*

check explanation at least - https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/discuss/2390802

 Time : O(n)
 Space : O(n) + O(n)   -memoization
         O(n)  - bottomUp
*/

class Solution {
public:
    
    #define vi vector<int>
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
 
    int n;
    int memo[100003];
    
    int partition(vi &a, int ind){
        
        if(ind>=n)
            return true;
        
        if(memo[ind] != -1){
            return memo[ind];
        }
        
        bool op1 = false, op2 = false, op3 = false;
        
        if(ind+1<n && a[ind] == a[ind+1])
            op1 = partition(a, ind+2) == 1;
    
        
        if(!op1 &&  (ind+2<n && a[ind] == a[ind+1] && a[ind] == a[ind+2])  ){
            op2 = partition(a, ind+3) == 1;
        }
        
        if( (!op1 && !op2) &&  ind+2<n && (1+a[ind] == a[ind+1]) && (2+a[ind] == a[ind+2])){
            op3 = partition(a, ind+3) == 1;
        }
        
        return memo[ind] = (op1 || op2 || op3) ? 1 : 0;
    }
    
    bool validPartition(vi& a) {
        
     this->n = a.size();    
     memset(memo, -1, sizeof(memo));
        
     // return partition(a, 0) == 1;   
        
        return bottomUp(a);
    }
    
    void printMemo(){
        
        for(int i=0; i<n+4; i++){
            cout<<memo[i]<<" ";
        }
        
        cout<<"\n-------\n";
        
    }
    
    bool bottomUp(vi &a){
        
        memo[n] =  memo[n+1] = memo[n+2]  = 1;
        
        for(int ind=n-1; ind>=0; ind--){
            
            bool op1 = false, op2 = false, op3 = false;
            
            if(ind+1<n && a[ind] == a[ind+1])
                op1 = memo[ind+2] == 1;


            if(!op1 &&  (ind+2<n && a[ind] == a[ind+1] && a[ind] == a[ind+2])  ){
                op2 = memo[ind+3] == 1;
            }

            if( (!op1 && !op2) &&  ind+2<n && (1+a[ind] == a[ind+1]) && (2+a[ind] == a[ind+2])){
                
                op3 = memo[ind+3] == 1;
            }
            
            memo[ind] = (op1 || op2 || op3) ? 1 : 0;
            
            // printMemo();
            
        }
        
        
        
        return memo[0] == 1;
        
    }
};

/*

[4,4,4,5,6]
[1,1,1,2]
[4,4,4,5,6,7,7,7]
[4,4,4,5,6,7,8,9]
[2,2,2,2,2,3,4]
[2,2,3]
[2,2,2,2]
[2,2,3,3,4,4]
[2,3,4]
[2,3,4,5,5,5,6,6]


*/
