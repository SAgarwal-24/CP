// link : https://leetcode.com/problems/palindrome-partitioning/

/*
1. logic : compute palindromes in 2d array - O(n^2)
2. recursion (backtracking) for partitioning

follow up - problems

https://leetcode.com/problems/palindrome-partitioning-ii/
https://leetcode.com/problems/palindrome-partitioning-iv/
https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

*/

class Solution {
public:
    
    #define vs vector<string>
    #define vi vector<int>
    #define vvi vector<vi>
    #define vvs vector<vs>
    
    void partitioning(string input, int st, vs &res, vvi &palindromes, vvs &ans){
        
        if(st >= input.size()){
            ans.push_back(res);
            return;
        }
        
        for(int end = st; end < input.size(); end++){
            
            if(palindromes[st][end] == 0){ // not a palindrome
                continue;
            }
            
            res.push_back(input.substr(st, end-st+1));
            partitioning(input,end+1,res,palindromes,ans);
            res.pop_back(); // backtrack
            
        }
    }
    
    vvs partition(string input) {
        
        int n = input.size(), i, j;
        
        vvs ans;
        
        // store palindromes in 2d-array , dp approach (subproblems computed first)
        vvi palindromes(n+1, vi(n+1, 0));
        
        for(int len=1; len<=n; len++){
            
            for(int st=0; st<=n-len; st++){
                
                
                // base case :  len = 1 , then it is palindrome
                
                if(len == 1){
                    palindromes[st][st] = 1;
                    continue;
                }
                
                int end = st + len - 1;
                
                if(len == 2){
                    palindromes[st][end] = input[st] == input[end];
                    continue;
                }
                
                
                palindromes[st][end] = (input[st] == input[end]) && palindromes[st+1][end-1] == 1;
                
                
                 // cout<<st<<","<<end<<" ";
                
            }
            
            // cout<<endl;
        }
        
        
        // now we can do partitioning using backtracking approach
        vs res;
        partitioning(input, 0, res, palindromes, ans);
        
        return ans;
    }
};

/*

n = 6
0 to 5
aabbcc


a a  b  b  c c
            cc
        
     bb 


   a  a  b  b  c  c

a  

a

b

b

c

c


0,0  1,1  2,2  3,3  4,4  5,5

0,1  1,2   .... 4,5

aaabbbcccdd

a aabbbcccdd   , aa, aaa, aaab, aaabb, aaabbb, aaabbbc

  a  abbbcccdd

*/
