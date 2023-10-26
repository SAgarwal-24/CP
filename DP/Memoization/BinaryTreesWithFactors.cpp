class Solution {
public:
    
    int MOD = 1e9 + 7;
    
    int numFactoredBinaryTrees(vector<int>& a) {
        
        int numOfTrees = 0, n = a.size();
        
        map<int, int>memo;
        sort(a.begin(), a.end());
        
        for(int i=0; i<n; i++){
            
            memo[ a[i] ] = 1; // since 'a[i]' is factor of itself there is always one factor or tree
            
            for(int j=0; j<i; j++){
                
                if(a[i] % a[j] != 0){
                    continue;
                }
                    
                
                int other = a[i] / a[j];
                
                memo[a[i]] =  ( memo[a[i]] + memo[a[j]] * 1LL * memo[other] ) % MOD;
                
            }
            
            
            numOfTrees = ( numOfTrees  + memo[a[i]] ) % MOD;
        }
        
   
        return numOfTrees;
    }
};

/*

2 4 8 16

2,4,8,16
-4,2,2

-8,4,2
-8,2,4

2,4,8,[4,2,2],[8,4,2],[8,2,4],[8]

[2,3,4,12]
2,3,4,12, [4,2,2], [12,4,3], [12,3,4], [12,2,2,3]



[2,4]
[2,4,5,10]
[2,4,5,10,11]
[2,4,5,10,11,12,14,16,17,18]
[2,4,5,10,11,20,22]
[2,4,5,10,11,12,14,16,17,18,26]




*/
