//link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    
    //anagram is basically a permutation and using frequency metric 
    // we can solve these kind of problems 
    
    vector<int> findAnagrams(string s, string p) {
        
        int i, n1=s.size(), n2=p.size();
        vector<int>ans;
        
        vector<int>fre(26,0);
        
        for(i=0;i<n2;i++)
            fre[p[i]-'a']+=1;
        
        int st=0, end=0;
        
        for(end=0; end<n1; end++){
            
            int ind = s[end]-'a';
            
            fre[ind]-=1;
            
            while(fre[ind]<0){ //we have either useless char or too many characters
                fre[s[st]-'a'] += 1;  //sliding window to remove character,
                st++;                   //'+' -:>remove, '-' ->to add
            }
            
            if(end-st+1 == n2){
                ans.push_back(st);
            }
        }
        
        return ans;
    }
};



