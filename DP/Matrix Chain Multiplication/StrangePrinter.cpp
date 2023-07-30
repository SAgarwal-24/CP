/*
link : https://leetcode.com/problems/strange-printer/

time : O(n*2 * n) = O(n*3)
space : O(n*2) 

*/

class Solution {
public:
    
    int memo[100][100];
    
    // s[l....r] = s[l...k] + s[k+1.....r] 
   int printSequence(string &s, int l, int r){
       
       if(l==r){ 
           return 1; // 1 turn reqd. to print a character
       }
       
       if(memo[l][r] != -1){ // memo[l][r] =  min turns to print s[l..r]
           return memo[l][r];
       }
       
       int minTurns = INT_MAX;
        
       for(int k=l; k<r; k++){ 
           minTurns =  min( minTurns , printSequence(s, l, k) +  printSequence(s, k+1, r));
       }
           
       return memo[l][r] =  (s[l] == s[r]) ? minTurns - 1 : minTurns ;
   }
        

    int strangePrinter(string s) {
       
        memset(memo, -1, sizeof(memo));

      return  printSequence(s, 0, s.size()-1);
        
    }
};

/*

"aaacbbbaac"
"aaacbbbaaca"
"acba"
"abca"
"abcab"
"abcabc"
"abcabca"

*/
