/*

- Number of Matching Subsequences
https://leetcode.com/problems/number-of-matching-subsequences/

Store indices of 26 character in a 2-D vector
Do Binary search on stored indices each time while finding subsequence 

m=words.length()
n=str.length()
l=words[i].length()

m <= 5*(10^3)
n <= 5*(10^4)
l <= 10

Time = O(m*l*log(n))

*/

class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int ans=0, i, len=s.size();
        
        vector<vector<int>>ind(26);
        
        //store indices of each character
        for(i=0;i<len;i++){
            ind[s[i]-'a'].push_back(i);
        }
        
        /* --- Uncomment to see the characters stored -----
        //Stored indices of 26 characters
        for(i=0;i<26;i++){
            
            cout<<char(i+'a')<<": ";
            
            for(auto x:ind[i])cout<<x<<" ";
            
            cout<<endl;
        }
       */
        
        
        for(auto str:words){ // O(m) 
            
            i=0;
            bool ok=true;
            
            for(auto ch:str){ // O(l)
                
                int low=0, hi=ind[ch-'a'].size()-1;
                int p=-1;
                
                while(low<=hi){ //binary search takes much less than O(log(n))
                    
                    int mid=low+(hi-low)/2;
                    
                    if(ind[ch-'a'][mid]>=i){
                        p=ind[ch-'a'][mid];
                        hi=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                    
                }
                
                if(p<i){ //suitable index is not found for matching subsequence
                    ok=false;
                    break;
                }
                
                i=p+1;
            }
            
            if(ok){ //subsequence matched 
                ans++;
            }
        }
        
        
        
        return ans;
    }
};

/*

"abexaezacdzdbe"
["a","bb","acd","ace"]

"abcde"
["a","bb","acd","ace"]

 "dsahjpjauf"
["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]

*/
