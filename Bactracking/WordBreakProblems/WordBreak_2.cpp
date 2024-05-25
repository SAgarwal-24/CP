// https://leetcode.com/problems/word-break-ii/

// check dp approach also 


class Solution {
public:
    
    #define  vs vector<string>
    
    
    void rec(string &s, int st, set<string> &dict,vs &sentenceWords, vs &ans){
        
        if(st >= s.size()){
            
            string frameSentence;
            int n = sentenceWords.size();
            
            if(n==0)
                return;
            
            for(int i=0; i<n; i++){
                frameSentence += sentenceWords[i];
                
                if( i!=n-1){
                    frameSentence += " ";
                }
            }
            
            ans.push_back(frameSentence);
            return;
        }
        
        
        for(int i=st; i<s.size(); i++){
            
           string sub = s.substr(st, i-st+1);
            
            if(dict.find(sub) != dict.end()){
                
                sentenceWords.push_back(sub);
                rec(s,i+1, dict,sentenceWords,ans);
                sentenceWords.pop_back(); // backtrack
            }
        }
    }
    
    vs wordBreak(string s, vs& wordDict) {
        
        vs ans;
        
        set<string>dict;
        for(auto w : wordDict){
            dict.insert(w);
        }
        
        vs sentenceWords;
        
        rec(s, 0, dict, sentenceWords, ans);
        
        return ans;
    }
};
