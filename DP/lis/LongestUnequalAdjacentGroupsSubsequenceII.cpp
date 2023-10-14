#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vs>
#define vvi vector<vi>
#define vd vector<double>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define watch(x) cout << (#x) << " -> "  << (x) << endl


class Solution {
public:
    
    bool checkHammingDistance(string &w1, string &w2){
        
        int n = w1.size(), different = 0;
        
        for(int i=0; i<n; i++){
            
            different += w1[i] != w2[i];
        }
        
        return different == 1;
    }
    
    vs getWordsInLongestSubsequence(int n, vs& words, vi& groups) {
        
        vs ans;
        int maxInd = 0, maxLen = 1;
        
        vi luags(n+1, 1); // length of - Longest Unequal Adjacent Groups Subsequence 
        vi prevIndex(n+1, -1);
        
        // LIS logic - just a story to deviate mind :)
        // O(n*2)
        for(int i=0; i<n; i++){
            
            prevIndex[i] = -1;
            
            for(int j=0; j<i; j++){
                
                if( groups[i] != groups[j] &&  
                    words[i].length() == words[j].length()  && 
                    checkHammingDistance(words[i], words[j])
                  ){
                    
                   
                    if( luags[i] < luags[j] + 1){
                         luags[i] = luags[j] + 1;                 
                         prevIndex[i] = j;
                    }
                }
                
                
            }
            
            
            if(maxLen <= luags[i]){
                maxLen = luags[i];
                maxInd = i;
            }
        }
        
        // retrieve longest subsequence - by iterating through previous indices
        int j = maxInd;
        while(j != -1){
            ans.pb(words[j]);
            j = prevIndex[j];
        }
        
        reverse(all(ans));
        
        return ans;
    }
};

