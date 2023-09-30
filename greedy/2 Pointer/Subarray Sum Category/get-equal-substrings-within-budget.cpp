/*
 link -> https://leetcode.com/problems/get-equal-substrings-within-budget/
 
 Same as -> longest subarray such that sum <= k (where k is maxCost and , sum is summation of differences)

*/

class Solution {
public:
    
    #define all(x) x.begin(), x.end()
    int equalSubstring(string s, string t, int maxCost) {
        
        vector<int>a;
        
        int i=0, n = s.size(), ans=0, st=0, sum=0;
        
        
        while(i<n){
            
            sum += abs(s[i] - t[i]);
            
            while(sum>maxCost){
                sum -= abs(s[st]-t[st]);
                st++;
            }
            
            ans = max(ans, i-st+1);
            
            i++;
            
        }
       
    
        return ans;
    }
};
/*
"krrgw"
"zjxss"
19
"abcd"
"bcdf"
3
"abcd"
"cdef"
3
"abcd"
"acde"
0
"abcd"
"acde"
2
"abcd"
"acde"
3
"abcd"
"acde"
4
"abcd"
"acde"
6
*/
