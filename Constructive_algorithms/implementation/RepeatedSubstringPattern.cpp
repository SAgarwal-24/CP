/*

https://leetcode.com/problems/repeated-substring-pattern/


see soln - https://leetcode.com/problems/repeated-substring-pattern/solution/

Time : O(N * N^(1/2))
Space :O(N)
*/

class Solution {
public:
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    bool repeatedSubstringPattern(string s) {
        
        int l, i, n = s.size();
        
        for(l=1; l<=n/2; l++){
            
            if(n % l != 0){
                continue;
            }
            
            string s1 = s.substr(0, l);
            bool ok = true;
            
            for(int st2=l; st2<n; st2 += l){
                
                
                if(st2 + l >= n+1){
                    ok = false;
                    break;
                }
                
                
                string s2 = s.substr(st2, l);
                
                if(s1 != s2){
                    ok = false;
                    break;
                }
            }
            
            if(ok){
                // watch(l);
                return true;
            }
                
        }
        
        return false;
    }
};

/*

"abab"
"aba"
"abcabcabcabc"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz"
"aaaaz"
*/
