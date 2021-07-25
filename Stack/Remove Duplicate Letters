// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ans="";
        
        int i,n=s.size();
        int fre[26]={0};
        
        // to remove multiple occurence specially for smallest character
        int vis[26]={0};
        
        
        for(i=1;i<n;i++){
            fre[s[i]-'a']+=1;
        }
        
        ans.push_back(s[0]);
        vis[s[0]-'a']=1;
        
        for(i=1;i<n;i++){
            
            char ch = s[i];
            
            if(vis[ch-'a']==1){
                fre[ch-'a']-=1;
                continue;
            }
            
            //if there is a bigger element then currenct char and has chance to occur later again then remove it
            while(!ans.empty() and ans.back()>=ch and fre[ans.back()-'a']>0){
              
                vis[ans.back()-'a']=0;
                  ans.pop_back();
            }
              
              fre[ch-'a']-=1;
              vis[ch-'a']=1;
            
              ans.push_back(ch);
            
              
        }
        
        return ans;
    }
};
/* ---tcs---
"bcabc"
"cbacdcbc"
"aaaaaa"
"ababab"
"bcabcadag"
"dcbaabcdewrta"
"onsdffsa"
"asijweaassijw"
"zxywzxwyu"
*/
