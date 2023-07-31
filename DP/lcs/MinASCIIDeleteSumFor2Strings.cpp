//  link - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// helpful - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/discuss/3563704/

class Solution {
public:
    

    int memo[1000][1000];
    
 
    int lcs(string &s1,string &s2, int i, int j){
        
        if( i>=s1.size() || j>=s2.size()){
            return 0;
        }
        
        if(memo[i][j] != -1){
            return memo[i][j]; // memo[i][j] = maxASCII of lcs of s1[i...n1] and s2[j...n2]
        }
        
        int ans = 0;
        
        if(s1[i] == s2[j]){         
           ans = s1[i] + lcs(s1, s2, i+1, j+1);  

        }
        else{
            ans = max( lcs(s1, s2, i+1, j),
                       lcs(s1, s2, i, j+1));
        }
        

        return  memo[i][j] = ans;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        
         memset(memo, -1, sizeof(memo));
            
         int lcsASCII = 0, totalASCII = 0;
         
                 
        for(int i=0; i<s1.size() || i<s2.size(); i++){           
            totalASCII +=  (i<s1.size()) ? s1[i] : 0;
            totalASCII +=  (i<s2.size()) ? s2[i] : 0;            
        }
        
        return totalASCII - 2*lcs(s1, s2, 0, 0);
        
        
    }
};

/*

"aaaasssssseddddddedeeee"
"xxxxxaaaaaayyyyyyssss"
*/
