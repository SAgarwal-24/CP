/*

https://leetcode.com/problems/excel-sheet-column-title/

time : O(log N)  with base 26 - In each iteration, the number  N gets divided by 26
space : O(1)


*/

class Solution {
public:
    string convertToTitle(int col) {
        
       
        string ans;
        
        char ch = 'A';
        
        while(col > 0){
            
            col--; // 0 based indexing 
            
            int r = col % 26; // append last char
            ans.push_back(ch + r );
            
            // cout<<ans<<endl;
              
            col = col/26;  // excel no.s are in base of 26
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

Excel Sheet Column Title
